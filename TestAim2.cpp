#include "AimHelper.h"
#include "HashHelpers.h"
#include "QuadraticProbingFull.h"
#include "QuadraticProbingPrefix.h"
#include "QuadraticProbingSimple.h"

#include <iostream>

using namespace std;

int main() {

  // open input file Ohenry.txt and load contents to vector of strings -
  // dataArray
  vector<string> dataArray;
  fileToArray("OHenry.txt", &dataArray);
  cout << "Data Array Size: " << dataArray.size() << endl;

  // open queries.txt andload contents to vector of strings "queryArray"
  vector<string> queryArray;
  fileToArray("queries.txt", &queryArray);
  cout << "Data Array Size: " << queryArray.size() << endl;

  // instantiate all three hashtables: ChainingHT, linearProbingHT,
  // QuadraticProbingHT
  QuadraticHashTableSimple<string> QuadraticProbingSimpleHT;
  QuadraticHashTablePrefix<string> QuadraticProbingPrefixHT;
  QuadraticHashTableFull<string> QuadraticProbingFullHT;
  double searchTime;

  // insert int quadratic HT
  QuadraticProbingSimpleHT.insertArray(&dataArray);
  cout << "\nQuadraticSimpleHT Current size:"
       << QuadraticProbingSimpleHT.getCurrentSize() << endl;

  cout << "Quadratic Probing Simple"
       << "\n"
       << "Elapsed Time " << QuadraticProbingSimpleHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time "
       << QuadraticProbingSimpleHT.getElapsedTime() /
              QuadraticProbingSimpleHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions " << QuadraticProbingSimpleHT.getCollisions() << "\n"
       << "#Unsuccessful Probes "
       << QuadraticProbingSimpleHT.getUnsuccessfulProbes() << "\n";
  searchTime = searchByQueryQS(&queryArray, &QuadraticProbingSimpleHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

  QuadraticProbingPrefixHT.insertArray(&dataArray);
  cout << "\nQuadraticPrefixHT Current size:"
       << QuadraticProbingPrefixHT.getCurrentSize() << endl;

  cout << "Quadratic Probing Prefix"
       << "\n"
       << "Elapsed Time " << QuadraticProbingPrefixHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time "
       << QuadraticProbingPrefixHT.getElapsedTime() /
              QuadraticProbingPrefixHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions " << QuadraticProbingPrefixHT.getCollisions() << "\n"
       << "#Unsuccessful Probes "
       << QuadraticProbingPrefixHT.getUnsuccessfulProbes() << "\n";
  searchTime = searchByQueryQP(&queryArray, &QuadraticProbingPrefixHT);
  cout << "Total search time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

  // Simple
  QuadraticProbingFullHT.insertArray(&dataArray);
  cout << "\nQuadraticFullHT Current size:"
       << QuadraticProbingFullHT.getCurrentSize() << endl;

  cout << "Quadratic Probing Full"
       << "\n"
       << "Elapsed Time " << QuadraticProbingFullHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time "
       << QuadraticProbingFullHT.getElapsedTime() /
              QuadraticProbingFullHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions " << QuadraticProbingFullHT.getCollisions() << "\n"
       << "#Unsuccessful Probes "
       << QuadraticProbingFullHT.getUnsuccessfulProbes() << "\n";
  searchTime = searchByQueryQF(&queryArray, &QuadraticProbingFullHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;
  return 0;
};
