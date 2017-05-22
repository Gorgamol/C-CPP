// file main_mp3_MENT_d.cpp
#include <iostream>

const int bitsPerOctet=8;

struct BinaryOctet {
  bool evenParity;   // set to true if number of '1' in bitsAsDigits is even, false otherwise
  char bitsAsDigits[bitsPerOctet]; // bit values as chars
};

std::ostream& operator<< (std::ostream& os, const BinaryOctet &toBePrinted){
	os << "(" << ")";
	return os;
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

BinaryOctet operator/ (BinaryOctet left, int right) {
  BinaryOctet result = intToBinaryOctet(binaryOctetToInt(left) / right);
  return result;
}

BinaryOctet operator-- (BinaryOctet toBeDecreased, int ) {
  BinaryOctet result = intToBinaryOctet(binaryOctetToInt(toBeDecreased) - 1);
  return result;
}

BinaryOctet operator&& ()
//typedef unsigned int calctype;
//typedef int calctype;
//typedef double calctype;
typedef BinaryOctet calctype;

/*calctype doCalculation(calctype a, calctype b){
    calctype result;
    // some calculation which doesnt make sense
    // but it should terminate quickly
    // do not try to understand it!
    for(; a && b; b--){
        a = a + 1;
        a = a / 2;
    }
    result = a + b;
    return result;
}*/

int main(int argc, char **argv)
{
    calctype a = {true, '0','1','0','1','0','1','0','1'};
    calctype b = {false, '0','0','0','1','0','1','0','1'};
    calctype c = a + (-1);
    c--;
    std::cout << "EvenParity => " << c.evenParity << std::endl;
    for(int i = 0; i < bitsPerOctet; ++i) {
      std::cout << c.bitsAsDigits[i];
    }
    std::cout << std::endl;
    //std::cout << "result = " << doCalculation(a,b) << std::endl;
    return 0;
}
