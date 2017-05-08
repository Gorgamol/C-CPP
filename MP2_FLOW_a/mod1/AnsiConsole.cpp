
#include "AnsiConsole.h"

AnsiConsole ansiConsole;


AnsiConsole::AnsiConsole(){
  pushCursorPos();
  hideCursor();
  clearScreen();
}

AnsiConsole::~AnsiConsole(){
  popCursorPos();
  showCursor();
}


void AnsiConsole::hideCursor(){
  std::cout << "\033[?25l";
}

void AnsiConsole::showCursor(){
  std::cout << "\033[?25h";
}

void AnsiConsole::pushCursorPos(){
  std::cout << "\033[s";
}

void AnsiConsole::popCursorPos(){
    std::cout << "\033[u";
}



void AnsiConsole::clearScreen(){
  std::cout << "\033[2J";
}


void AnsiConsole::printText(int x, int y, std::string text, Colors color){
  std::cout << "\033[" << y << ";" << x <<  "f"; // move cursor to x,y
  std::cout << "\033[0;" << static_cast<int>(color) << "m"; //  blue
  std::cout << text;
  std::cout << "\033[0m\n"; // reset attributes
}
