/*
 * Cullen Williams & Garrick Hutcheson
 * Aim1
 */

#include "AimHelper.h"


using namespace std;

int main() {

  // open input file Ohenry.txt and load contents to vector of strings -
  // dataArray
  vector<string> dataArray;
  fileToArray("OHenry.txt", &dataArray);

  // open queries.txt andload contents to vector of strings "queryArray"
  vector<string> queryArray;
  fileToArray("queries.txt", &queryArray);

  // instantiate all three hashtables: ChainingHT, linearProbingHT,
  // QuadraticProbingHT
  ChainingHashTable<string> ChainingHT;
  QuadraticHashTable<string> QuadraticProbingHT;
  LinearHashTable<string> LinearProbingHT;
  double searchTime;

  // insert into chaining HT
  ChainingHT.insertArray(&dataArray);

  // insert into quadratic HT
  QuadraticProbingHT.insertArray(&dataArray);

  LinearProbingHT.insertArray(&dataArray);

  searchTime = searchByQuery(&queryArray, &QuadraticProbingHT);
  displayStatistics("Quadratic Probing HashTable", queryArray.size(), searchTime, &QuadraticProbingHT);

  searchTime = searchByQuery(&queryArray, &ChainingHT);
  displayStatistics("Chaining HashTable", queryArray.size(), searchTime, &ChainingHT);

  searchTime = searchByQuery(&queryArray, &LinearProbingHT);
  displayStatistics("Linear Probing HashTable", queryArray.size(), searchTime, &LinearProbingHT);



  return 0;
};
