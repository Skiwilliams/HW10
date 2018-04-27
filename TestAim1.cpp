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

<<<<<<< HEAD
  //print some stuff
  cout << "\nChaining "<<"\n";
  cout << "Elapsed Time " << cHash.getElapsedTime() << " micro seconds\n";
  cout << "Average Time " << cHash.getElapsedTime()/cHash.getCurrentSize() << " micro seconds\n";  
  cout << "Collisions " << cHash.getCollisions() << "\n";
   //<<"#UnsuccessfulProbes " << cHash.getUnsuccessfulProbes() << "\n"
  cout << "We found " << searchByQueryC(&queryArray, &cHash)<< "/" << queryArray.size() << "\n"<<endl;

  cout << "\nQuadratic Probing "<<"\n";
  cout << "Elapsed Time " << qHash.getElapsedTime() << " micro seconds\n";
  cout << "Average Time " << cHash.getElapsedTime()/cHash.getCurrentSize() << " micro seconds\n";    
  cout << "Collisions " << qHash.getCollisions() << "\n";
  cout <<"#Unsuccessful Probes " << qHash.getUnsuccessfulProbes() << "\n";
  cout << "We found " << searchByQueryQ(&queryArray, &qHash)<< "/" << queryArray.size() << "\n"<<endl;

  cout << "\nLinear Probing "<<"\n";
  cout << "Elapsed Time " << lHash.getElapsedTime() << " micro seconds\n";
  cout << "Average Time " << cHash.getElapsedTime()/cHash.getCurrentSize() << " micro seconds\n";    
  cout << "Collisions " << lHash.getCollisions() << "\n";
  cout <<"#Unsuccessful Probes " << lHash.getUnsuccessfulProbes() << "\n";
  cout << "We found " << searchByQueryL(&queryArray, &lHash) <<"/" << queryArray.size() << "\n"<<endl;
=======
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
>>>>>>> 0a8c447a8843047b7a32d46cf68374b60741fa92

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
