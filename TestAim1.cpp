#include <iostream>
#include "HashHelpers.h"
#include "AimHelper.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"

using namespace std;

int main() {
  /*
    opens input file Ohenry.txt
    loads contents to vector of strings - dataArray
  */
  vector<string> dataArray;
  vector<string> queryArray;

  string fileName = "OHenry.txt";//line not used

  fileToArray("OHenry.txt", &dataArray);
  fileToArray("queries.txt", &queryArray);

  ChainingHashTable<string> cHash;
  QuadraticHashTable<string> qHash;
  LinearHashTable<string> lHash;

  cHash.insertArray(&dataArray);
  qHash.insertArray(&dataArray);
  lHash.insertArray(&dataArray);


  //print some stuff
  cout << "\nChaining "<<"\n";
  cout << "ElapsedTime " << cHash.getElapsedTime() << "\n";
  cout << "Collisions " << cHash.getCollisions() << "\n";
   //<<"#UnsuccessfulProbes " << cHash.getUnsuccessfulProbes() << "\n"
  cout << "We found " << searchByQueryC(&queryArray, &cHash)<< "/" << queryArray.size() << "\n"<<endl;

  cout << "\nQuadratic Probing "<<"\n";
  cout << "ElapsedTime " << qHash.getElapsedTime() << "\n";
  cout << "Collisions " << qHash.getCollisions() << "\n";
  cout <<"#UnsuccessfulProbes " << qHash.getUnsuccessfulProbes() << "\n";
  cout << "We found " << searchByQueryQ(&queryArray, &qHash)<< "/" << queryArray.size() << "\n"<<endl;

  cout << "\nLinear Probing "<<"\n";
  cout << "ElapsedTime " << lHash.getElapsedTime() << "\n";
  cout << "Collisions " << lHash.getCollisions() << "\n";
  cout <<"#UnsuccessfulProbes " << lHash.getUnsuccessfulProbes() << "\n";
  cout << "We found " << searchByQueryL(&queryArray, &lHash) <<"/" << queryArray.size() << "\n"<<endl;



  /*
  for(vector<string>::iterator iter = dataArray.begin(); iter < dataArray.end(); iter++)
  {
    cout << *iter <<endl;
  }
  
  
  cout << "\n\n\n\n\n\n" << endl;
  
  getchar();
  
  for(vector<string>::iterator iter = queryArray.begin(); iter < queryArray.end(); iter++)
  {
    cout << *iter << endl;
  }
  */
  
  /*
    opens queries.txt
    loads contents to vector of strings "queryArray"
  */
  
  /*
    instantiates all three hashtables
      ChainingHT, linearProbingHT, QuadraticProbingHT
  */
  
  /*
    ANALYSIS OF CHAINING
    call function insertIntoChainingHT(DataArray)
    Initializes INSERTIONTIMERCHAININGHT
    initialises and keeps track of CollisionsChainingHT that counts total
     number of collisions accross all insertions (Note  that  this  is  same  as  counting  the 
    total  number  of  times  you  are  inside  the  while  loop  within 
    function findPos() across all insertions.)
    calls SearchChaingingHT(QueryArray)
  */
  
  
  /*
    insertIntoChainingHT(array)
    inserts words into DataArray no duplicate words are allowed
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
