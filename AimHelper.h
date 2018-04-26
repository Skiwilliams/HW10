/*
 * Cullen Williams & Garrick Hutcheson
 * Aim1.h
 */

#ifndef AIMHELPER_H
#define AIMHELPER_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

<<<<<<< HEAD
void getSomeWords(std::vector<string> *OhenryArray);
void getSomeWordsQuery(std::vector<string> *OhenryArray);
int searchByQueryQ(std::vector<std::string> *queryArray,
                   QuadraticHashTable<string> *h1);
int searchByQueryL(std::vector<std::string> *queryArray,
                   LinearHashTable<string> *h1);

int searchByQueryC(std::vector<std::string> *queryArray,
                   ChainingHashTable<string> *h1);
=======
void fileToArray(string fileName, std::vector<string> *OhenryArray);
>>>>>>> 76eac7ee0a8a94acebf24479e01fce07c43b222e
/*
  inserts words into DataArray no duplicate words are allowed
*/
// void insertIntoChainingHT(DataArray);//call function
// insertIntoChainingHT(DataArray)

/*
  private member holds the sum of times taken for all insertions
  function adds an insert time to private member
*/
// void insertionTimerChainingHT();

/*
  counts number of total collisions
  equal to times entering the findPos while loop
*/
// void CollisionChainingHT();

/*
  does a find for every query in the list of queries
  adds time
*/
// void SearchChaingingHT(QueryArray);

// vector dataArray<string>;
/*
  int insertionTimerChainingHT;//holds the sum of times taken for all insertions
  int CollisionCounterChainingHT;
  int SearchTimerChainingHT;

  int insertionTimerQProbeSimple;
  int insertionTimerQProbePrefix;
  int insertionTimerQProbeFull;

  int CollisionCounterQProbeSimple;
  int CollisionCounterQProbePrefix;
  int CollisionCounterQProbeFull;

*/
#endif
