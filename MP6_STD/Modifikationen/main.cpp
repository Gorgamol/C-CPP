#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

const int bitsPerOctet = 8;

struct BinaryOctet {
  bool evenParity;
  char bitsAsDigits[bitsPerOctet];

  explicit BinaryOctet(int a) {
    evenParity = false;
    int count = 0;
    for(int i = 0; i < bitsPerOctet; i++) {
      if(a % 2 != 0) {
        bitsAsDigits[bitsPerOctet - i - 1] = '1';
        count++;
      } else {
        bitsAsDigits[bitsPerOctet - i - 1] = '0';
      }
      a = a / 2;
    }
    if(count % 2 == 0) {
      evenParity = true;
    }
  }

  bool operator < (const BinaryOctet &other) const;
  std::string toString() const;
};

int binaryOctetToInt(BinaryOctet a) {
  int result = 0;
  for(int i = 0; i < bitsPerOctet; i++) {
    result = result * 2 + (a.bitsAsDigits[i] - 48);
  }
  return result;
}

bool BinaryOctet::operator < (const BinaryOctet& other) const {
  if(binaryOctetToInt(*this) < binaryOctetToInt(other)) {
    return true;
  } else {
    return false;
  }
}

std::string BinaryOctet::toString() const {
    std::string s = "";
    for(int i = 0; i < bitsPerOctet; i++) {
      s += bitsAsDigits[i];
    }
    return s + " - " + std::to_string(binaryOctetToInt(*this));
}

std::ostream& operator<< (std::ostream& os, const BinaryOctet &toBePrinted){
	os << toBePrinted.toString();
	return os;
}

template <typename Iterator>
void containerPrint(Iterator it, Iterator end) {
  char t = '"';
  for(; it != end; it++) {
    std::cout << t << *(it) << t << ",";
  }
  std::cout << std::endl;
}

template <typename Iterator>
bool containerContains(Iterator it, Iterator end, int x) {
  for(; it != end; it++) {
    if(*(it) == x) {
      return true;
    }
  }
  return false;
}

template <typename Container>
void generateRands_unsorted(Container &c) {
  int random = 0;
  for(int i = 0; i < 15; i++) {
    random = std::rand() % 100 + 0;
    if(!containerContains(c.begin(), c.end(), random)) {
      c.push_back(random);
    }
  }
}

template <typename Container>
void generateRands_sorted(Container &c) {
  int random = 0;
  typename Container::iterator it;
  for(int i = 0; i < 15; i++) {
    random = std::rand() % 100 + 0;
    if(!containerContains(c.begin(), c.end(), random)) {
      c.insert(std::upper_bound(c.begin(), c.end(), random), random);
    }
  }
}

int main() {
  std::srand(std::time(0)); // use current time as seed for random generator
  std::vector<int> vecRands;
  std::list<int> listRands;

  std::cout << "\nVector unsortiert gefüllt:" << std::endl;
  generateRands_unsorted(vecRands);
  containerPrint(vecRands.begin(), vecRands.end());

  std::cout << "\nList unsortiert gefüllt:" << std::endl;
  generateRands_unsorted(listRands);
  containerPrint(listRands.begin(), listRands.end());

  std::cout << "\nVector sortiert gefüllt:" << std::endl;
  vecRands.clear();
  generateRands_sorted(vecRands);
  containerPrint(vecRands.begin(), vecRands.end());

  std::cout << "\nList sortiert gefüllt:" << std::endl;
  listRands.clear();
  generateRands_sorted(listRands);
  containerPrint(listRands.begin(), listRands.end());

  std::cout << "\nstd::vector<BinaryOctet> unsortiert" << std::endl;
  std::vector<BinaryOctet> vecBinaryOctet;
  for(int i = 0; i < 10; i++) {
    vecBinaryOctet.push_back(static_cast<BinaryOctet>(std::rand() % 100 + 0));
  }

  for(auto v : vecBinaryOctet) {
    std::cout << v << std::endl;
  }

  std::cout << "\nstd::vector<BinaryOctet> sortiert" << std::endl;
  std::sort(vecBinaryOctet.begin(), vecBinaryOctet.end());

  for(auto v : vecBinaryOctet) {
    std::cout << v << std::endl;
  }
}
