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
using namespace std;

/*
  inserts words into DataArray no duplicate words are allowed
*/
void getSomeWords(std::vector<std::string> *OhenryArray) {
  std::string inname = "";
  std::ifstream fin;
  fin.open("OHenry.txt");
  while (!fin.eof()) {
    std::getline(fin, inname);
    OhenryArray->push_back(inname);
  }
}

void getSomeWordsQuery(std::vector<std::string> *OhenryArray) {
  std::string inname = "";
  std::ifstream fin;
  fin.open("OHenry.txt");
  while (!fin.eof()) {
    std::getline(fin, inname);
    OhenryArray->push_back(inname);
  }
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
