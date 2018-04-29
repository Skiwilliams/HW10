#include "AimHelper.h"

using namespace std;

int main() {
  double searchTime;

  // creates a data and query arrays
  vector<string> dataArray;
  vector<string> queryArray;

  // loads data into data and query array
  fileToArray("OHenry.txt", &dataArray);
  fileToArray("queries.txt", &queryArray);

  // instantiate all three hashtables: ChainingHT, linearProbingHT,
  ChainingHashTable<string> ChainingHT;
  QuadraticHashTable<string> QuadraticProbingHT;
  LinearHashTable<string> LinearProbingHT;

  // insert into chaining HT
  ChainingHT.insertArray(&dataArray);
  QuadraticProbingHT.insertArray(&dataArray);
  LinearProbingHT.insertArray(&dataArray);

  /* Chaining results */
  searchTime = searchByQueryC(&queryArray, &ChainingHT);
  cout << "\nChaining\n"
       << "Elapsed Time:            " << ChainingHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time:            "
       << ChainingHT.getElapsedTime() / ChainingHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions:              " << ChainingHT.getCollisions()
       << "\nTotal Search Time:       " << searchTime
       << "\nAverage Time per search: " << searchTime / queryArray.size()
       << endl;

  /* Quadratic probing results */
  searchTime = searchByQueryQ(&queryArray, &QuadraticProbingHT);
  cout << "\nQuadratic Probing\n"
       << "Elapsed Time:            " << QuadraticProbingHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time:            "
       << QuadraticProbingHT.getElapsedTime() /
              QuadraticProbingHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions:              " << QuadraticProbingHT.getCollisions()
       << "\n#Unsuccessful Probes:    "
       << QuadraticProbingHT.getUnsuccessfulProbes()
       << "\nTotal Search Time:       " << searchTime
       << "\nAverage Time per search: " << searchTime / queryArray.size()
       << endl;

  /* Linear probing results */
  searchTime = searchByQueryL(&queryArray, &LinearProbingHT);
  cout << "\nLinear Probing\n"
       << "Elapsed Time:            " << LinearProbingHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time:            "
       << LinearProbingHT.getElapsedTime() / LinearProbingHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions:              " << LinearProbingHT.getCollisions()
       << "\n#Unsuccessful Probes:    "
       << LinearProbingHT.getUnsuccessfulProbes()
       << "\nTotal Search Time:       " << searchTime << " micro seconds"
       << "\nAverage Time per search: " << searchTime / queryArray.size()
       << " micro seconds" << endl;

  return 0;
};
