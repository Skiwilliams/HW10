#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <algorithm>
#include <ctime>
#include <functional>
#include <list>
#include <string>
#include <vector>
#include "HashHelpers.h"
using namespace std;


// SeparateChaining Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items

template <typename HashedObj> class ChainingHashTable {
public:
  explicit ChainingHashTable(int size = 101) : currentSize{0} {
    collisions = 0;
    elapsedTime = 0;
    theLists.resize(101);
  }

  bool contains(const HashedObj &x) const {
    auto &whichList = theLists[myhash(x)];
    return find(begin(whichList), end(whichList), x) != end(whichList);
  }

  void makeEmpty() {
    for (auto &thisList : theLists)
      thisList.clear();
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
    auto &whichList = theLists[myhash(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList)) {
      elapsedTime += clock() - start;
      return false;
    }
    if (!whichList.empty())
      collisions++;
    whichList.push_back(x);

    // Rehash; see Section 5.5
    if (++currentSize > theLists.size())
      rehash();
    elapsedTime += clock() - start;
    return true;
  }

  bool insert(HashedObj &&x) {
    clock_t start = clock();
    auto &whichList = theLists[myhash(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList)) {
      elapsedTime += clock() - start;
      return false;
    }
    if (!whichList.empty())
      collisions++;
    whichList.push_back(x);

    // Rehash; see Section 5.5
    if (++currentSize > theLists.size())
      rehash();
    elapsedTime += clock() - start;
    return true;
  }

  bool remove(const HashedObj &x) {
    auto &whichList = theLists[myhash(x)];
    auto itr = find(begin(whichList), end(whichList), x);

    if (itr == end(whichList))
      return false;

    whichList.erase(itr);
    --currentSize;
    return true;
  }

  int getCurrentSize() { return currentSize; }

  int getElapsedTime() { return elapsedTime; }

  int getCollisions() { return collisions; }

private:
  vector<list<HashedObj>> theLists; // The array of Lists
  int currentSize;
  int collisions;
  int elapsedTime;

  void rehash() {
    vector<list<HashedObj>> oldLists = theLists;

    // Create new double-sized, empty table
    theLists.resize(nextPrime(2 * theLists.size()));
    for (auto &thisList : theLists)
      thisList.clear();

    // Copy table over
    currentSize = 0;
    for (auto &thisList : oldLists)
      for (auto &x : thisList)
        insert(std::move(x));
  }

  size_t myhash(const HashedObj &x) const {
    static hash<HashedObj> hf;
    return hf(x) % theLists.size();
  }
};

#endif
