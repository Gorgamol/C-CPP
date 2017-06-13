#include <iostream>
#include "FixedPoint.hpp"
#include "Bargeld.hpp"


int main() {
  Bargeld* muenze = new Bargeld_Muenze(5.23);
  Bargeld* schein = new Bargeld_Schein(5.22, 1);
  std::cout << *muenze << std::endl;
  std::cout << *schein << std::endl;
  std::cout << dynamic_cast<Bargeld_Schein*>(schein)->getSeriennummer() << std::endl;
  std::cout << (*(muenze) + *(schein)) << std::endl;
  delete muenze;
  delete schein;
  return 0;
}
