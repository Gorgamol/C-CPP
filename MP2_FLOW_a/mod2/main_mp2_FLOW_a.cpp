#include <stdio.h>  /* file main_mp2_FLOW_a.cpp */
#include <string>
#include "AnsiConsole.h"

AnsiConsole console; int firstLine; int currentTick; Colors currentColor;
#define INITPRINT(label) {firstLine=__LINE__;console.printText(2*currentTick,0,label,Colors::BLACK);}
#define PRINT printLineNumber(__LINE__)
void printLineNumber(int lineNumber);

















void func();

void print() {
  INITPRINT("TEST");
  PRINT; for(int i = 0; i < 4; ++i) {
    PRINT; func();
  } PRINT;
}





void func() {
  PRINT;
}

int main(int argc, const char * argv[]) {
  console.clearScreen();
  currentColor = Colors::GREEN;
  print();

  //start_goto();
  //start_switch();
  //start_interrupt();
  //start_coroutine();
  //start_exception();
  std::string s;
  std::cin >> s;
  return 0;
}

void printLineNumber(int lineNumber){
  std::string line = std::to_string(lineNumber);
  console.printText(currentTick*2, 1+lineNumber-firstLine, line, currentColor);
  currentTick++;
}
