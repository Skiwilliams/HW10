#include <iostream>
#include "SeparateChaining.h"
#include "QuadraticProbing.h"
#include "LinearProbing.h"
#include "AimHelper.h"

using namespace std;

int main() {
  /*
    opens input file Ohenry.txt
    loads contents to vector of strings - dataArray
  */
  vector<string> dataArray;
  vector<string> queryArray;
  string fileName = "OHenry.txt";
  fileToArray("OHenry.txt", &dataArray);
  fileToArray("queries.txt", &queryArray);
  SeperateHashTable<string> sHash;
  QuadraticHashTable<string> qHash;
  LinearHashTable<string> lHash;
  sHash.insertArray(&dataArray);
  qHash.insertArray(&dataArray);
  lHash.insertArray(&dataArray);

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
  
}
