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

#endif