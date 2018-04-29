#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H


#include "QuadraticProbing.h"



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

template <typename HashedObj> class LinearHashTable: public QuadraticHashTable<HashedObj> {
public:
      using QuadraticHashTable<HashedObj>::myhash;
      using QuadraticHashTable<HashedObj>::array;
      using QuadraticHashTable<HashedObj>::currentSize;
      using QuadraticHashTable<HashedObj>::collisions;
      using QuadraticHashTable<HashedObj>::unsuccessfulProbes;
      using QuadraticHashTable<HashedObj>::elapsedTime;
      using QuadraticHashTable<HashedObj>::EMPTY;
  explicit LinearHashTable(string hashFunction = "standard") :
    QuadraticHashTable<HashedObj>(101, hashFunction) {
    }

protected:


  int findPos(const HashedObj &x) {
    int offset = 1;      
    int currentPos = myhash(x);

    if (array[currentPos].info != EMPTY && array[currentPos].element != x)
      collisions++;
    while (array[currentPos].info != EMPTY && array[currentPos].element != x) {
      currentPos += offset; // Compute ith probe
      if (currentPos >= array.size())
        currentPos -= array.size();
      unsuccessfulProbes++;
    }

    return currentPos;
  }

};

#endif
