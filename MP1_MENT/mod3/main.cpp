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

PascalString intToHex(int n) {
  PascalString s;
  int temp;
  for(int i = 0; n != 0; i++) {
    if(n % 16 == 0) {
      s.characters[i] = '0';
    } else {
      temp = n % 16;
      if(temp >= 0 && temp <= 9) {
        s.characters[i] = temp + 48;
      } else {
              std::cout << ">>> " << temp << std::endl;
              s.characters[i] = temp + 87;
      }
    }
    n = n/16;
    s.length = i + 1;
  }

  PascalString returnValue;
  returnValue.length = s.length;
  for(int i = s.length - 1; i >= 0; --i) {
    returnValue.characters[s.length - i - 1] = s.characters[i];
  }

  return returnValue;
}

void printPascalString(PascalString s) {
  for(int i = 0; i < s.length; ++i) {
    std::cout << s.characters[i];
  }
  std::cout << std::endl;
}

int main(int argc, char** argv, char**envp) {
  PascalString s = {3, '1', '0', '0'};
  PascalString s2 = {4, 'f', 'f', 'f', 'f'};
  std::cout << hexStringToInt(s) << std::endl;
  std::cout << hexStringToInt(s2) << std::endl;
  printPascalString(intToHex(9));
  return 0;
}
