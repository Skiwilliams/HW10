/*
 * Cullen Williams & Garrick Hutcheson
 * Aimhelper
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

void displayStatistics(std::string name, int numQueries, double searchTime, QuadraticHashTable<std::string> *h1)
{
cout << "\n"<< name <<  "\n"
       << "Elapsed Insertion Time:\t\t" << h1->getElapsedTime()
       << " micro seconds\n"
       << "Average Time Per Insertion:\t"
       << h1->getElapsedTime() / h1->getCurrentSize()
       << " micro seconds\n"
       << "Collisions:\t\t\t" << h1->getCollisions()
       << "\n#Unsuccessful Probes:\t\t"
       << h1->getUnsuccessfulProbes()
       << "\nTotal Search Time:\t\t" << searchTime << " micro seconds"
       << "\nAverage Time per search: \t" << searchTime / numQueries
       << " micro seconds" << endl;
}

#endif