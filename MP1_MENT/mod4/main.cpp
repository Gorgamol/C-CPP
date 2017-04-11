#include <iostream>

struct PascalString {
  int length;
  char characters[265];
};

int hexDigitToInt(char hexDigit) {
  int returnValue = -1;
  if(hexDigit >= 48 && hexDigit <= 57) {
    returnValue = hexDigit - 48;
  } else {
      if(hexDigit >= 97 && hexDigit <= 102) {
        returnValue = hexDigit - 87;
      }
  }
  return returnValue;
}

int hexStringToInt(PascalString binaryDigits) {
  int returnValue = 0;
  int potenz = 1;
  for(int i = 0; i < binaryDigits.length; ++i) {
      if(i == 0) {
        returnValue += (hexDigitToInt(binaryDigits.characters[binaryDigits.length - 1 - i]) * potenz);
      } else {
          for(int j = 0; j < i; ++j) {
            potenz = potenz * 16;
          }
          returnValue += (hexDigitToInt(binaryDigits.characters[binaryDigits.length - 1 - i]) * potenz);
      }
      potenz = 1;
  }
  return returnValue;
}

PascalString bitwiseDualAnd(PascalString a, PascalString b) {
  PascalString result;
  if(a.length > b.length) {
    result.length = a.length;
    for(int i = a.length - 1; i >= 0; --i) {
      if(i > (a.length - b.length)) {
              result.characters[i] = a.characters[i] & b.characters[i];
      } else {
        result.characters[i] = 0;
      }
     }
  } else if(a.length < b.length){
    result.length = b.length;
    for(int i = b.length - 1; i >= 0; --i) {
      if(i > (b.length - a.length)) {
              result.characters[i] = b.characters[i] & a.characters[i];
      } else {
        result.characters[i] = 0;
      }
     }
  } else {
    result.length = a.length;
    for(int i = a.length - 1; i >= 0; --i) {
      result.characters[i] = a.characters[i] & b.characters[i];
    }
  }

  return result;
}

void printPascalString(PascalString s) {
  for(int i = 0; i < s.length; ++i) {
    std::cout << s.characters[i];
  }
  std::cout << std::endl;
}

int main(int argc, char** argv, char**envp) {
  PascalString s = {4, '1', '0', '1', '0'};
  PascalString s2 = {4, '0', '1', '0', '1'};
  printPascalString(bitwiseDualAnd(s, s2));
  return 0;
}
