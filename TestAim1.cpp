#include "AimHelper.h"
#include "HashHelpers.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"
#include <iostream>

using namespace std;

int main() {

  /*
    open input file Ohenry.txt
    load contents to vector of strings - dataArray
  */
  vector<string> dataArray;
  fileToArray("OHenry.txt", &dataArray);
  cout << "Data Array Size: " << dataArray.size() <<endl;
  /*
   open queries.txt
   load contents to vector of strings "queryArray"
 */
  vector<string> queryArray;
  fileToArray("queries.txt", &queryArray);

  /*
  instantiate all three hashtables
    ChainingHT, linearProbingHT, QuadraticProbingHT
*/
  ChainingHashTable<string> ChainingHT;
  QuadraticHashTable<string> QuadraticProbingHT;
  LinearHashTable<string> LinearProbingHT;

  ChainingHT.insertArray(&dataArray);         // InsertIntoChainingHT
  cout << "ChainingHT Current size:" << ChainingHT.getCurrentSize() << endl;
  QuadraticProbingHT.insertArray(&dataArray); // InsertIntoQuadraticHT
    cout << "QuadraticHT Current size:" << QuadraticProbingHT.getCurrentSize() << endl;
  LinearProbingHT.insertArray(&dataArray);    // InsertIntoLinearHT
  cout << "LinearProbingHT Current size:" << LinearProbingHT.getCurrentSize() << endl;

  // print some stuff
  cout << "\nChaining "
       << "\n";
  cout << "ElapsedTime " << ChainingHT.getElapsedTime() << "\n";
  cout << "Collisions " << QuadraticProbingHT.getCollisions() << "\n";
  //<<"#UnsuccessfulProbes " << ChainingHT.getUnsuccessfulProbes() << "\n"
  cout << ChainingHT.contains("cop") << endl;
  // searchByQueryC(&queryArray, &ChainingHT);
  //<< "out of" << queryArray.size() << "\n"<<endl;

  cout << "\nQuadratic Probing "
       << "\n";
  cout << "ElapsedTime " << QuadraticProbingHT.getElapsedTime() << "\n";
  cout << "Collisions " << QuadraticProbingHT.getCollisions() << "\n";
  cout << "#UnsuccessfulProbes " << QuadraticProbingHT.getUnsuccessfulProbes() << "\n";
  // cout << "We found " << searchByQueryQ(&queryArray, &QuadraticProbingHT)<< "/" <<
  // queryArray.size() << "\n"<<endl;

  cout << "\nLinear Probing "
       << "\n";
  cout << "ElapsedTime " << LinearProbingHT.getElapsedTime() << "\n";
  cout << "Collisions " << LinearProbingHT.getCollisions() << "\n";
  cout << "#UnsuccessfulProbes " << LinearProbingHT.getUnsuccessfulProbes() << "\n";
  // cout << "We found " << searchByQueryL(&queryArray, &LinearProbingHT) <<"/" <<
  // queryArray.size() << "\n"<<endl;
/*
  for (vector<string>::iterator iter = dataArray.begin();
       iter < dataArray.end(); iter++) {
    cout << *iter << endl;
  }

  cout << "\n\n\n\n\n\n" << endl;

  getchar();

  for (vector<string>::iterator iter = queryArray.begin();
       iter < queryArray.end(); iter++) {
    cout << *iter << endl;
  }
*/
  /*
    ANALYSIS OF CHAINING
    call function insertIntoChainingHT(DataArray)
    Initializes INSERTIONTIMERCHAININGHT
    initialises and keeps track of CollisionsChainingHT that counts total
     number of collisions accross all insertions (Note  that  this  is  same  as
    counting  the total  number  of  times  you  are  inside  the  while  loop
    within function findPos() across all insertions.) calls
    SearchChaingingHT(QueryArray)
  */



  /*
    insertionTimerChainingHT()
    private member holds the sum of times taken for all insertions
    function adds an insert time to private member
  */

  /*
    SearchChaingingHT(QueryArray)
    does a find for every query in the list of queries
    adds time
  */
  return 0;
};
