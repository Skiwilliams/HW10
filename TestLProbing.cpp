#include "AimHelper.h"
#include "LinearProbing.h"
#include <iostream>
using namespace std;

// Simple main
int main() {

  std::vector<std::string> OhenryArray;
  getSomeWords(&OhenryArray);

  vector<string>::iterator iter = OhenryArray.begin();

  for (std::vector<string>::iterator it = OhenryArray.begin();
       it != OhenryArray.end(); ++it) {
    std::cout << "hello " << *it << endl;
  }

  LinearHashTable<string> h1;
  h1.insertArray(&OhenryArray);
  cout << h1.getElapsedTime() << " elapsed time" << endl;
  cout << h1.getCollisions() << " collisions" << endl;
  cout << h1.getUnsuccessfulProbes() << " #unsuccessfulProbes" << endl;
  /*
      h2 = h1;

      for (i = 1; i < NUMS; i += 2)
          h2.remove(i);

      for (i = 2; i < NUMS; i += 2)
          if (!h2.contains(i))
              cout << "Contains fails " << i << endl;

      for (i = 1; i < NUMS; i += 2)
      {
          if (h2.contains(i))
              cout << "OOPS!!! " << i << endl;
      }
  */
  return 0;
}
