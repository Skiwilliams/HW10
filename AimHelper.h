/*
 * Cullen Williams & Garrick Hutcheson
 * Aim1.h
 */
#ifndef AIMHELPER_H
#define AIMHELPER_H

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

double searchByQueryQ(std::vector<std::string> *queryArray,
                      QuadraticHashTable<string> *h1) {
  int queriesFound = 0;
  clock_t start = clock();
  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    queriesFound += h1->contains(iter->data());
  }
  return clock() - start;
}


double searchByQueryL(std::vector<std::string> *queryArray,
                      LinearHashTable<string> *h1) {
  clock_t start = clock();
  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    h1->contains(iter->data());
  }
  return clock() - start;
}

double searchByQueryC(std::vector<std::string> *queryArray,
                      ChainingHashTable<string> *h1) {
  int queriesFound = 0;
  clock_t start = clock();

  for (std::vector<string>::iterator iter = queryArray->begin();
       iter != queryArray->end(); iter++) {
    queriesFound += h1->contains(iter->data());
  }
  return clock() - start;
}

#endif