#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include "Hash.h"
#include "HashHelpers.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using std::clock_t;
using std::string;
using std::vector;
using namespace StringHash;

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename HashedObj> class QuadraticHashTable {
public:
  explicit QuadraticHashTable(int size = 101, string hashFunction = "standard")
      : array(nextPrime(size)) {
    makeEmpty();
    collisions = 0;
    unsuccessfulProbes = 0;
    elapsedTime = 0;
    setHashFunction(hashFunction);
  }

  bool contains(const HashedObj &x) { return isActive(findPos(x)); }

  void makeEmpty() {
    currentSize = 0;
    for (auto &entry : array)
      entry.info = EMPTY;
  }

  bool insertArray(std::vector<HashedObj> *inArray) {
    typename vector<HashedObj>::iterator iter = inArray->begin();
    while (iter != inArray->end()) {
      insert(*iter);
      iter++;
    }
  }

  bool insert(const HashedObj &x) {
    clock_t start = clock();
    // Insert x as active
    int currentPos = findPos(x);
    if (isActive(currentPos)) {
      return false;
      elapsedTime += clock() - start;
    }
    if (array[currentPos].info != DELETED)
      ++currentSize;

    array[currentPos].element = x;
    array[currentPos].info = ACTIVE;

    // Rehash; see Section 5.5
    if (currentSize > array.size() / 2)
      rehash();
    elapsedTime += clock() - start;
    return true;
  }

  bool insert(HashedObj &&x) {
    clock_t start = clock();
    // Insert x as active
    int currentPos = findPos(x);
    if (isActive(currentPos)) {
      elapsedTime += clock() - start;
      return false;
    }

    if (array[currentPos].info != DELETED)
      ++currentSize;

    array[currentPos] = std::move(x);
    array[currentPos].info = ACTIVE;

    // Rehash; see Section 5.5
    if (currentSize > array.size() / 2)
      rehash();
    elapsedTime += clock() - start;
    return true;
  }

  bool remove(const HashedObj &x) {
    int currentPos = findPos(x);
    if (!isActive(currentPos))
      return false;

    array[currentPos].info = DELETED;
    return true;
  }

  int getCurrentSize() { return currentSize; }

  double getElapsedTime() { return elapsedTime; }

  int getCollisions() { return collisions; }

  int getUnsuccessfulProbes() { return unsuccessfulProbes; }

  void setHashFunction(string hashfunction) {
      if(hashfunction == "simple")
      {
        hf = new SimpleHash;
      }
      else if(hashfunction == "prefix")
      {
        hf = new PrefixHash;
      }
      else if (hashfunction == "full")
      {
        hf = new FullHash;
      }
      else
      {
        hf = new Hash;
      }
  }

  enum EntryType { ACTIVE, EMPTY, DELETED };

private:
  struct HashEntry {
    HashedObj element;
    EntryType info;

    HashEntry(const HashedObj &e = HashedObj{}, EntryType i = EMPTY)
        : element{e}, info{i} {}

    HashEntry(HashedObj &&e, EntryType i = EMPTY)
        : element{std::move(e)}, info{i} {}
  };

  vector<HashEntry> array;
  int currentSize;
  int collisions;
  int unsuccessfulProbes;
  double elapsedTime;
  Hash* hf;

  bool isActive(int currentPos) const {
    return array[currentPos].info == ACTIVE;
  }

  int findPos(const HashedObj &x) {
    int offset = 1;
    int currentPos = myhash(x);
    if (array[currentPos].info != EMPTY && array[currentPos].element != x) {
      collisions++;
    }
    while (array[currentPos].info != EMPTY && array[currentPos].element != x) {
      currentPos += offset; // Compute ith probe
      offset += 2;
      if (currentPos >= array.size())
        currentPos -= array.size();
      unsuccessfulProbes++;
    }
    return currentPos;
  }

  void rehash() {
    vector<HashEntry> oldArray = array;

    // Create new double-sized, empty table
    array.resize(nextPrime(2 * oldArray.size()));
    for (auto &entry : array)
      entry.info = EMPTY;

    // Copy table over
    currentSize = 0;
    for (auto &entry : oldArray)
      if (entry.info == ACTIVE)
        insert(std::move(entry.element));
  }

  size_t myhash(const HashedObj &x) const { return (*hf)(x) % array.size(); }
};

#endif
