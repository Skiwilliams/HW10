/*
 * Cullen Williams & Garrick Hutcheson
 * Aim1.h
 */
#ifndef AIMHELPER_H
#define AIMHELPER_H

#include <fstream>
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

double searchByQuery(std::vector<std::string> *queryArray,
                      QuadraticHashTable<string> *h1) {
  int queriesFound = 0;
  clock_t start = clock();
  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    queriesFound += h1->contains(iter->data());
  }
  return clock() - start;
}



#endif