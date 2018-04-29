/*
 * Cullen Williams & Garrick Hutcheson
 * Aim2
 */

#include "AimHelper.h"

using namespace std;

int main() {

  // open input file Ohenry.txt and load contents to vector of strings -
  // dataArray
  double searchTime = 0;
  vector<string> dataArray;
  fileToArray("OHenry.txt", &dataArray);
  cout << "Data Array Size: " << dataArray.size() << endl;

  // open queries.txt andload contents to vector of strings "queryArray"
  vector<string> queryArray;
  fileToArray("queries.txt", &queryArray);

  // instantiate all three hashtables: SimpleHT, FullHT,
  // SimpleHT
  QuadraticHashTable<string> SimpleHT(101, "simple");
  QuadraticHashTable<string> PrefixHT(101, "prefix");
  QuadraticHashTable<string> FullHT(101, "full");


  //inserting
  SimpleHT.insertArray(&dataArray);
  PrefixHT.insertArray(&dataArray);
  FullHT.insertArray(&dataArray);

  //Querying and displaying stats
  searchTime = searchByQuery(&queryArray, &SimpleHT);
  displayStatistics("Simple Hash Algorithm", queryArray.size(), searchTime, &SimpleHT);
  searchTime = searchByQuery(&queryArray, &PrefixHT);
  displayStatistics("Prefix Hash Algorithm", queryArray.size(), searchTime, &PrefixHT);
  searchTime = searchByQuery(&queryArray, &FullHT);
  displayStatistics("Full Hashing Algorithm", queryArray.size(), searchTime, &FullHT);

  return 0;
};
