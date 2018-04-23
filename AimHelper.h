/*
 * Cullen Williams & Garrick Hutcheson
 * Aim1.h
 */

#ifndef AIMHELPER_H
#define AIMHELPER_H

#include <iostream>
#include <vector>
using namespace std;

void getSomeWords(std::vector<string> *OhenryArray);
void getSomeWordsQuery(std::vector<string> *OhenryArray);
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
