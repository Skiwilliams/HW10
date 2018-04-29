#include "AimHelper.h"
#include "QuadraticProbing.h"

#include <iostream>

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
  cout << "Query Array Size: " << queryArray.size() << endl;

  // instantiate all three hashtables: SimpleHT, FullHT,
  // SimpleHT
  QuadraticHashTable<string> SimpleHT(101, "simple");
  QuadraticHashTable<string> PrefixHT(101, "prefix");
  QuadraticHashTable<string> FullHT(101, "full");

   // insert into chaining HT
  SimpleHT.insertArray(&dataArray);
  cout << "SimpleHT Current size:" << SimpleHT.getCurrentSize() << endl;

  // insert int quadratic HT
  PrefixHT.insertArray(&dataArray);
  cout << "PrefixHT Current size:" << PrefixHT.getCurrentSize()
       << endl;

  FullHT.insertArray(&dataArray);
  cout << "FullHT Current size:" << FullHT.getCurrentSize()
    << endl;


  cout << "\nSimple Hashing "
       << "\n";
  cout << "Elapsed Time " << SimpleHT.getElapsedTime()
       << " micro seconds\n";
  cout << "Average Time "
       << SimpleHT.getElapsedTime() /
              SimpleHT.getCurrentSize()
       << " micro seconds\n";
  cout << "Collisions " << SimpleHT.getCollisions() << "\n";
  cout << "#Unsuccessful Probes " << SimpleHT.getUnsuccessfulProbes()
       << "\n";
  searchTime = searchByQueryQ(&queryArray, &SimpleHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

         // print some stuff
  cout << "\nPrefix Hashing "
       << "\n";
  cout << "Elapsed Time " << PrefixHT.getElapsedTime() << " micro seconds\n";
  cout << "Average Time "
       << PrefixHT.getElapsedTime() / PrefixHT.getCurrentSize()
       << " micro seconds\n";
  cout << "Collisions " << PrefixHT.getCollisions() << "\n";
  //<<"#UnsuccessfulProbes " << cHash.getUnsuccessfulProbes() << "\n"
  searchTime = searchByQueryQ(&queryArray, &PrefixHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

 
  cout << "\n Full Hashing "
       << "\n";
  cout << "Elapsed Time " << FullHT.getElapsedTime()
       << " micro seconds\n";
  cout << "Average Time "
       << FullHT.getElapsedTime() / FullHT.getCurrentSize()
       << " micro seconds\n";
  cout << "Collisions " << FullHT.getCollisions() << "\n";
  cout << "#Unsuccessful Probes " << FullHT.getUnsuccessfulProbes()
       << "\n";
  searchTime = searchByQueryQ(&queryArray, &FullHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;
  return 0;
};
