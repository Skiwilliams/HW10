#ifndef _HASH_H
#define _HASH_H
#include <string>
namespace StringHash {
struct Hash {

  virtual std::size_t operator()(const std::string &key) const {
    static std::hash<std::string> hf;
    return hf(key);
  }
};

struct SimpleHash : Hash {
  std::size_t operator()(const std::string &key) const {
    int hashVal = 0;
    for (char ch : key)
      hashVal += ch;
    return hashVal;
  }
};

struct PrefixHash : Hash {
  std::size_t operator()(const std::string &key) const {
    return (key[0] + 27 * key[1] + 729 * key[2]);
  }
};

struct FullHash : Hash {
  std::size_t operator()(const std::string &key) const {
    unsigned int hashVal = 0;
    for (char ch : key)
      hashVal = 37 * hashVal + ch;
    return hashVal;
  }
};
} // namespace hash

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}


#endif