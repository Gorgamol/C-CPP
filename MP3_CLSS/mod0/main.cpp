// file main_mp3_CLSS_e.cpp
#include <iostream>

const int bitsPerOctet=8;


struct BinaryOctet {
  bool evenParity;   // set to true if number of '1' in bitsAsDigits is even, false otherwise
  char bitsAsDigits[bitsPerOctet]; // bit values as chars
  BinaryOctet() {
    evenParity = false;
    for(int i = 0; i < bitsPerOctet; i++) {
      bitsAsDigits[i] = '0';
    }
  }
  BinaryOctet(int a) {
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
  std::string toString();
};

std::string BinaryOctet::toString() {
    std::string s = "";
    for(int i = 0; i < bitsPerOctet; i++) {
      s += bitsAsDigits[i];
    }
    return s;
}

int binaryOctetToInt(BinaryOctet a) {
  int result = 0;
  for(int i = 0; i < bitsPerOctet; i++) {
    result = result * 2 + (a.bitsAsDigits[i] - 48);
  }
  return result;
}

BinaryOctet intToBinaryOctet(int a) {
  BinaryOctet result;
  result.evenParity = false;
  int count = 0;
  for(int i = 0; i < bitsPerOctet; i++) {
    if(a % 2 != 0) {
      result.bitsAsDigits[bitsPerOctet - i - 1] = '1';
      count++;
    } else {
      result.bitsAsDigits[bitsPerOctet - i - 1] = '0';
    }
    a = a / 2;
  }
  if(count % 2 == 0) {
    result.evenParity = true;
  }
  return result;
}

BinaryOctet operator+ (BinaryOctet left, BinaryOctet right) {
  BinaryOctet result = intToBinaryOctet(binaryOctetToInt(left) + binaryOctetToInt(right));
  return result;
}

BinaryOctet operator+ (BinaryOctet left, int right) {
  BinaryOctet result = intToBinaryOctet(binaryOctetToInt(left) + right);
  return result;
}

BinaryOctet operator/ (BinaryOctet left, BinaryOctet right) {
  BinaryOctet result = intToBinaryOctet(binaryOctetToInt(left) / binaryOctetToInt(right));
  return result;
}

BinaryOctet operator-- (BinaryOctet toBeDecreased, int) {
  BinaryOctet result = intToBinaryOctet(binaryOctetToInt(toBeDecreased) - 1);
  return result;
}

bool operator!= (BinaryOctet left, BinaryOctet right) {
  if(binaryOctetToInt(left) == binaryOctetToInt(right)) {
    return true;
  }
  return false;
}

BinaryOctet doCalculation(BinaryOctet a, BinaryOctet b){
  BinaryOctet result;

  for(; a != b; b--){
    a = a + 1;
    a = a / b;
  }
  result = a + b;

  return result;
}

std::ostream& operator<< (std::ostream& os, const BinaryOctet &toBePrinted){
	os << BinaryOctet::toString(toBePrinted);
	return os;
}

int main(int argc, char **argv)
{
  BinaryOctet a = 0b00001111;
  BinaryOctet b = 0b00000110;
  std::cout << "result = " << doCalculation(a,b) << std::endl;

    return 0;
}
