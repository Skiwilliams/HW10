/*
 * Cullen Williams & Garrick Hutcheson
 * Aim1.h
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"

using namespace std;

/*
  inserts words into DataArray no duplicate words are allowed
*/
void fileToArray(string fileName, std::vector<std::string> *StringArray) {
  std::string inname = "";
  std::ifstream fin;
  fin.open(fileName);
  while (!fin.eof()) {
    std::getline(fin, inname);
    StringArray->push_back(inname);
  }
}

<<<<<<< HEAD
void getSomeWordsQuery(std::vector<std::string> *OhenryArray) {
  std::string inname = "";
  std::ifstream fin;
  fin.open("queries.txt");
  while (!fin.eof()) {
    std::getline(fin, inname);
    OhenryArray->push_back(inname);
  }
}
=======

>>>>>>> 76eac7ee0a8a94acebf24479e01fce07c43b222e

int searchByQueryQ(std::vector<std::string> *queryArray,
                   QuadraticHashTable<string> *h1) {
  int queriesFound = 0;
  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    queriesFound += h1.contains(iter->data());
    iter++;
  }
  return queriesFound;
}

int searchByQueryL(std::vector<std::string> *queryArray,
                   LinearHashTable<string> *h1) {
  int queriesFound = 0;
  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    queriesFound += h1.contains(iter->data());
    iter++;
  }
  return queriesFound;
}

int searchByQueryC(std::vector<std::string> *queryArray,
                   ChainingHashTable<string> *h1) {
  int queriesFound = 0;
  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    queriesFound += h1->contains(iter->data());
    iter++;
  }
  return queriesFound;
}

/*
  private member holds the sum of times taken for all insertions
  function adds an insert time to private member
*/
// void insertionTimerChainingHT() {}

/*
  counts number of total collisions
  equal to times entering the findPos while loop
*/
// void CollisionChainingHT() {}

/*
  does a find for every query in the list of queries
  adds time
*/
// void SearchChaingingHT() {}

// private:
// vector dataArray<string>;
// vector queryArray<string>;
