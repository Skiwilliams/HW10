#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "SeparateChaining.h"
#include <iostream>

using namespace std;

<<<<<<< HEAD
// Simple main
int main() {
  QuadraticHashTable<int> h1;
  QuadraticHashTable<int> h2;
  LinearHashTable<int> h3;
  LinearHashTable<int> h4;
  SeperateHashTable<int> h5;
  SeperateHashTable<int> h6;

  const int NUMS = 4000;
  const int GAP = 37;
  vector<int> testArray = {1001, 1002, 1003, 1004, 1005};
  int i;

  cout << "Checking... (no more output means success)" << endl;

  /*
  for (i = GAP; i != 0; i = (i + GAP) % NUMS)
    h1.insert(i);

  h2 = h1;

  for (i = 1; i < NUMS; i += 2)
  h2.remove(i);

  for (i = 2; i < NUMS; i += 2)
    if (!h2.contains(i))
      cout << "Contains fails " << i << endl;

  for (i = 1; i < NUMS; i += 2) {
    if (h2.contains(i))
      cout << "OOPS!!! " << i << endl;
  }
  */
  h1.insertArray(testArray);
  cout << h1.getElapsedTime() << " elapsed time" << endl;
  cout << h1.getCollisions() << " collisions" << endl;
  cout << h1.getUnsuccessfulProbes() << " #unsuccessfulProbes" << endl;

  for (i = GAP; i != 0; i = (i + GAP) % NUMS)
    h3.insert(i);

  h4 = h3;

  for (i = 1; i < NUMS; i += 2)
    h4.remove(i);

  for (i = 2; i < NUMS; i += 2)
    if (!h4.contains(i))
      cout << "Contains fails " << i << endl;

  for (i = 1; i < NUMS; i += 2) {
    if (h4.contains(i))
      cout << "OOPS!!! " << i << endl;
  }
  h3.insertArray(&testArray);
  cout << h3.getElapsedTime() << " elapsed time" << endl;
  cout << h3.getCollisions() << " collisions" << endl;
  cout << h3.getUnsuccessfulProbes() << " #unsuccessfulProbes" << endl;

  for (i = GAP; i != 0; i = (i + GAP) % NUMS)
    h5.insert(i);

  h6 = h5;

  for (i = 1; i < NUMS; i += 2)
    h6.remove(i);

  for (i = 2; i < NUMS; i += 2)
    if (!h6.contains(i))
      cout << "Contains fails " << i << endl;

  for (i = 1; i < NUMS; i += 2) {
    if (h6.contains(i))
      cout << "OOPS!!! " << i << endl;
  }
  h5.insertArray(testArray);
  cout << h5.getElapsedTime() << endl;
  cout << h5.getCollisions() << endl;

  return 0;
=======
    // Simple main
int main( )
{
    QuadraticHashTable<int> h1;
    QuadraticHashTable<int> h2;
    LinearHashTable<int> h3;
    LinearHashTable<int> h4;
    SeperateHashTable<int> h5;
    SeperateHashTable<int> h6;

    const int NUMS = 500;
    const int GAP  =   37;
    vector<int> testArray= {1001, 1002, 1003, 1004, 1005};
    int i;
    
    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        h1.insert( i );
    
    h2 = h1;
    
    for( i = 1; i < NUMS; i += 2 )
        h2.remove( i );
    
    for( i = 2; i < NUMS; i += 2 )
        if( !h2.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( h2.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }
    

    h1.insertArray(&testArray);
    

    cout<< h1.getElapsedTime() <<endl;
    cout<< h1.getCollisions() <<endl;
    cout<< h1.getUnsuccessfulProbes() <<endl;

      for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        h3.insert( i );
    
    h4 = h3;

    
    for( i = 1; i < NUMS; i += 2 )
        h4.remove( i );

    for( i = 2; i < NUMS; i += 2 )
        if( !h4.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( h4.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }
    
    

    h3.insertArray(&testArray);
    cout<< h3.getElapsedTime() <<endl;
    cout<< h3.getCollisions() <<endl;
    cout<< h3.getUnsuccessfulProbes() <<endl;

  for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        h5.insert( i );
    
    h6 = h5;
    
    for( i = 1; i < NUMS; i += 2 )
        h6.remove( i );

    for( i = 2; i < NUMS; i += 2 )
        if( !h6.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( h6.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }
    
    h5.insertArray(&testArray);

    cout<< h5.getElapsedTime() <<endl;
    cout<< h5.getCollisions() <<endl;


    return 0;
>>>>>>> d53e4903663485492bb5c6a67798aef8a9ec784c
}
