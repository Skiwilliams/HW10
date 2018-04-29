#include "AimHelper.h"


using namespace std;

int main() {

  // open input file Ohenry.txt and load contents to vector of strings -
  // dataArray
  vector<string> dataArray;
  fileToArray("OHenry.txt", &dataArray);

  // open queries.txt andload contents to vector of strings "queryArray"
  vector<string> queryArray;
  fileToArray("queries.txt", &queryArray);

  // instantiate all three hashtables: ChainingHT, linearProbingHT,
  // QuadraticProbingHT
  ChainingHashTable<string> ChainingHT;
  QuadraticHashTable<string> QuadraticProbingHT;
  LinearHashTable<string> LinearProbingHT;
  double searchTime;

  // insert into chaining HT
  ChainingHT.insertArray(&dataArray);

  // insert int quadratic HT
  QuadraticProbingHT.insertArray(&dataArray);


  // print some stuff

  //<<"#UnsuccessfulProbes " << cHash.getUnsuccessfulProbes() << "\n"
  searchTime = searchByQuery(&queryArray, &ChainingHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

  cout << "\nQuadratic Probing "
       << "\n";
  cout << "Elapsed Time " << QuadraticProbingHT.getElapsedTime()
       << " micro seconds\n";
  cout << "Average Time "
       << QuadraticProbingHT.getElapsedTime() /
              QuadraticProbingHT.getCurrentSize()
       << " micro seconds\n";
  cout << "Collisions " << QuadraticProbingHT.getCollisions() << "\n";
  cout << "#Unsuccessful Probes " << QuadraticProbingHT.getUnsuccessfulProbes()
       << "\n";
  searchTime = searchByQuery(&queryArray, &QuadraticProbingHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

  LinearProbingHT.insertArray(&dataArray);
  cout << "\nLinear Probing "
       << "\n";
  cout << "Elapsed Time " << LinearProbingHT.getElapsedTime()
       << " micro seconds\n";
  cout << "Average Time "
       << LinearProbingHT.getElapsedTime() / LinearProbingHT.getCurrentSize()
       << " micro seconds\n";
  cout << "Collisions " << LinearProbingHT.getCollisions() << "\n";
  cout << "#Unsuccessful Probes " << LinearProbingHT.getUnsuccessfulProbes()
       << "\n";
  searchTime = searchByQuery(&queryArray, &LinearProbingHT);
  cout << "Total time " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << "\n"
       << endl;

  return 0;
};
