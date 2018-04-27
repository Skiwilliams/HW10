#include "AimHelper.h"
#include "HashHelpers.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"
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
  ChainingHashTable<string> ChainingHT;
  QuadraticHashTable<string> QuadraticProbingHT;
  LinearHashTable<string> LinearProbingHT;

  // insert into chaining HT
  ChainingHT.insertArray(&dataArray);
  cout << "ChainingHT Current size:" << ChainingHT.getCurrentSize() << endl;

  // insert int quadratic HT
  QuadraticProbingHT.insertArray(&dataArray);
  cout << "QuadraticHT Current size:" << QuadraticProbingHT.getCurrentSize()
       << endl;

  // InsertIntoLinearHT
  LinearProbingHT.insertArray(&dataArray);
  cout << "LinearProbingHT Current size:" << LinearProbingHT.getCurrentSize()
       << endl;

  // Chaining data
  cout << "\nChaining " << "\n";
  cout << "ElapsedTime " << ChainingHT.getElapsedTime() << "\n";
  cout << "Collisions " << QuadraticProbingHT.getCollisions() << "\n";
  cout << "Found" << searchByQueryC(&queryArray, &ChainingHT) << "/"
       << queryArray.size() << " queries\n"
       << endl;

  //Quadratic Data
  cout << "\nQuadratic Probing "
       << "\n";
  cout << "ElapsedTime " << QuadraticProbingHT.getElapsedTime() << "\n";
  cout << "Collisions " << QuadraticProbingHT.getCollisions() << "\n";
  cout << "#UnsuccessfulProbes " << QuadraticProbingHT.getUnsuccessfulProbes()
       << "\n";
  cout << "Found " << searchByQueryQ(&queryArray, &QuadraticProbingHT) << "/"
       << queryArray.size() << " queries\n"
       << endl;

  //Linear Data
  cout << "\nLinear Probing "
       << "\n";
  cout << "ElapsedTime " << LinearProbingHT.getElapsedTime() << "\n";
  cout << "Collisions " << LinearProbingHT.getCollisions() << "\n";
  cout << "#UnsuccessfulProbes " << LinearProbingHT.getUnsuccessfulProbes()
       << "\n";
  cout << "Found " << searchByQueryL(&queryArray, &LinearProbingHT) << "/"
       << queryArray.size() << " queries\n"
       << endl;


  return 0;
};
