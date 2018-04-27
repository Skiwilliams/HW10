#include "AimHelper.h"
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"
#include <iostream>

using namespace std;

// Simple main
int main() {
  QuadraticHashTable<string> h1;
  LinearHashTable<string> h3;
  ChainingHashTable<string> h5;

  vector<string> testArray;
  getSomeWords(&testArray);

  vector<string> queryArray;
  getSomeWordsQuery(&queryArray);

  h1.insertArray(&testArray);

  cout << "\nElapsedTime " << h1.getElapsedTime() << endl;
  cout << "Collisions " << h1.getCollisions() << endl;
  cout << "#UnsuccessfulProbes " << h1.getUnsuccessfulProbes() << endl;
  cout << "We found " << searchByQueryQ(&queryArray, &h1) << endl;

  h3.insertArray(&testArray);
  cout << "\nElapsedTime " << h3.getElapsedTime() << endl;
  cout << "Collisions " << h3.getCollisions() << endl;
  cout << "#UnsuccessfulProbes " << h3.getUnsuccessfulProbes() << endl;

  h5.insertArray(&testArray);

  cout << "\nElapsedTime " << h5.getElapsedTime() << endl;
  cout << "Collisions " << h5.getCollisions() << endl;

  return 0;
}
