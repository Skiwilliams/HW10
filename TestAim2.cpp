#include "AimHelper.h"

using namespace std;

int main() {

  double searchTime = 0;

  // creates a data and query arrays
  vector<string> dataArray;
  vector<string> queryArray;

  // loads data into data and query array
  fileToArray("OHenry.txt", &dataArray);
  fileToArray("queries.txt", &queryArray);

  // instantiate all three hashtables: SimpleHT, FullHT,
  QuadraticHashTable<string> SimpleHT(101, "simple");
  QuadraticHashTable<string> PrefixHT(101, "prefix");
  QuadraticHashTable<string> FullHT(101, "full");

  // inserts into Hash Tables
  SimpleHT.insertArray(&dataArray);
  PrefixHT.insertArray(&dataArray);
  FullHT.insertArray(&dataArray);

  /* simple hashing results */
  searchTime = searchByQueryQ(&queryArray, &SimpleHT);
  cout << "\nSimple Hashing\n"
       << "Elapsed Time:            " << SimpleHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time:            "
       << SimpleHT.getElapsedTime() / SimpleHT.getCurrentSize()
       << " micro seconds"
       << "\nCollisions:              " << SimpleHT.getCollisions()
       << "\n#Unsuccessful Probes:    " << SimpleHT.getUnsuccessfulProbes()
       << "\n#Total Search Time:       " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << endl;

  /* prefix hashing results */
  searchTime = searchByQueryQ(&queryArray, &PrefixHT);
  cout << "\nPrefix Hashing\n"
       << "Elapsed Time:            " << PrefixHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time:            "
       << PrefixHT.getElapsedTime() / PrefixHT.getCurrentSize()
       << " micro seconds"
       << "\nCollisions:              " << PrefixHT.getCollisions()
       << "\n#Unsuccessful Probes:    " << PrefixHT.getUnsuccessfulProbes()
       << "\n#Total Search Time:       " << searchTime
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << endl;

  /* full hashing results */
  searchTime = searchByQueryQ(&queryArray, &FullHT);
  cout << "\nFull Hashing\n"
       << "Elapsed Time:            " << FullHT.getElapsedTime()
       << " micro seconds\n"
       << "Average Time:            "
       << FullHT.getElapsedTime() / FullHT.getCurrentSize()
       << " micro seconds\n"
       << "Collisions               " << FullHT.getCollisions()
       << "\n#Unsuccessful Probes:    " << FullHT.getUnsuccessfulProbes()
       << "\n#Total Search Time:       " << searchTime << " micro seconds"
       << "\nAverage time per search: " << searchTime / queryArray.size()
       << " micro seconds" << endl;
  return 0;
};
