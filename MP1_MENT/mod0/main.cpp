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

void printPascalString(PascalString s) {
  for(int i = 0; i < s.length; ++i) {
    std::cout << s.characters[i] << std::endl;
  }
}

PascalString intToOctal(int n) {
  PascalString tempString;
  tempString.length = 0;
  int i = 0;
  while(n != 0) {
    if(n < 8) {
     tempString.length++;
     tempString.characters[i] = n + 48;
   }else if(n % 8 != 0) {
      tempString.length++;
      tempString.characters[i] = n % 8;
    } else if(n % 8 == 0){
      tempString.length++;
      tempString.characters[i] = '0';
    }
    ++i;
    n = n/8;
  }

  PascalString returnString;
  returnString.length = tempString.length;
  std::cout << "länge " << returnString.length << std::endl;
  i = 0;
  for(int j = tempString.length - 1; j >= 0; --j) {
    returnString.characters[i] = tempString.characters[j];
    ++i;
  }
  return returnString;
}

int main(int argc, char** argv, char**envp) {
  PascalString s = {3, '1', '0', '0'};
  PascalString s2 = {4, 'f', 'f', 'f', 'f'};
  printPascalString(intToOctal(16));
  return 0;
}
