#include "Konto.hpp"
#include <iostream>


Konto::Konto(std::string inhaber) : inhaber(inhaber) {

}

Konto::~Konto() {
  kontostand.clear();
  std::cout << "Konto Destructor()" << std::endl;
}
