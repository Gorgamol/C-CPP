// file main_mp3_MENT_d.cpp
#include <iostream>

const int bitsPerOctet=8;

struct BinaryOctet {
  bool evenParity;   // set to true if number of '1' in bitsAsDigits is even, false otherwise
  char bitsAsDigits[bitsPerOctet]; // bit values as chars
};

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

std::ostream& operator<< (std::ostream& os, const BinaryOctet &toBePrinted){
	os << "(" << ")";
	return os;
}

BinaryOctet operator+ (BinaryOctet left, BinaryOctet right) {
  int carry = 0;
  int temp = 0;
  calctype result;
  result.evenParity = false;
  for(int i = bitsPerOctet - 1; i >= 0; --i) {
    temp = (left.bitsAsDigits[i] - 48) + (right.bitsAsDigits[i] - 48);
    if(temp > 1) {
      if(carry == 1) {
        result.bitsAsDigits[i] = '1';
        carry = 1;
      } else {
        carry = 1;
        result.bitsAsDigits[i] = '0';
      }
    } else if(temp == 1) {
      if(carry == 1) {
        result.bitsAsDigits[i] = '0';
      } else {
        result.bitsAsDigits[i] = '1';
        carry = 0;
      }
    } else {
      if(carry == 1) {
        result.bitsAsDigits[i] = '1';
        carry = 0;
      } else {
        result.bitsAsDigits[i] = '0';
      }
    }
  }

  int n = 0;
  for(int i = 0; i < bitsPerOctet; ++i) {
    if(result.bitsAsDigits[i] - 48 == 1) {
      ++n;
    }
  }

  if(n % 2 == 0) {
    result.evenParity = true;
  }
  return result;
}

/*BinaryOctet operator/ (BinaryOctet left, BinaryOctet right) {

}*/


int main(int argc, char **argv)
{
    calctype a = {true, '0','1','0','1','0','1','0','1'};
    calctype b = {false, '0','0','0','1','0','1','0','1'};
    calctype c = a + b;
    std::cout << "EvenParity => " << c.evenParity << std::endl;
    for(int i = 0; i < bitsPerOctet; ++i) {
      std::cout << c.bitsAsDigits[i];
    }
    std::cout << std::endl;
    //std::cout << "result = " << doCalculation(a,b) << std::endl;
    return 0;
}
