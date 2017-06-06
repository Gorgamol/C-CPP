#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

bool contains(std::vector<char>::iterator it, std::vector<char>::iterator end, char &c) {
  for(; it != end; it++) {
    if(*(it) == c) {
      return true;
    }
  }
  return false;
}

int stringSimilarity(std::string &a, std::string &b) {
  std::vector<char> vecA(a.begin(), a.end());
  std::vector<char> vecB(b.begin(), b.end());
  std::vector<char> in_common;

  for(char c1 : vecA) {
    for(char c2: vecB) {
      if((c1 == c2) && !(contains(in_common.begin(), in_common.end(), c1))) {
        in_common.push_back(c1);
      }
    }
  }

  if(!a.compare(b)) {
    return 100;
  } else if(a.size() == b.size()) {
    return (100 / a.size()) * in_common.size();
  } else {
    return (100 / ((a.size() + b.size()) / 2)) * in_common.size();
  }

  return -1;
}

void unittest_stringSimilarity() {
  std::string a = "test";
  std::string b = "test";
  std::cout << "Unittest: [" << a << " <> " << b << "] " << stringSimilarity(a,b) << std::endl;
  a = "test";
  b = "tset";
  std::cout << "Unittest: [" << a << " <> " << b << "] " << stringSimilarity(a,b) << std::endl;
  a = "test123";
  b = "unittest123";
  std::cout << "Unittest: [" << a << " <> " << b << "] " << stringSimilarity(a,b) << std::endl;
  a = "w";
  b = "q";
  std::cout << "Unittest: [" << a << " <> " << b << "] " << stringSimilarity(a,b) << std::endl;
}

int main() {
  unittest_stringSimilarity();
  return 0;
}
