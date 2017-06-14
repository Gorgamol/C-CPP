#include "Bargeld.hpp"

Bargeld::Bargeld(float wert) : wert(wert) {

}

Bargeld::~Bargeld() {

}

FixedPoint Bargeld::getWert(void) const {
  return wert;
}

  FixedPoint Bargeld::operator+(const Bargeld &b) const {
    return this->getWert() + b.getWert();
  }

  FixedPoint Bargeld::operator-(const Bargeld &b) const {
    return this->getWert() - b.getWert();
  }

  bool Bargeld::operator==(const FixedPoint &b) const {
    return this->getWert() == b;
  }

Bargeld_Schein::Bargeld_Schein(float wert, int seriennummer) : Bargeld(wert), seriennummer(seriennummer) {

}

Bargeld_Schein::~Bargeld_Schein() {
  std::cout << "Bargeld_Schein Destructor()" << std::endl;
}

int Bargeld_Schein::getSeriennummer(void) {
  return seriennummer;
}

Bargeld_Muenze::Bargeld_Muenze(float wert) : Bargeld(wert) {

}

Bargeld_Muenze::~Bargeld_Muenze() {
  std::cout << "Bargeld_Muenze Destructor()" << std::endl;
}

std::ostream& operator << (std::ostream& os, const Bargeld& toBePrinted) {
  os << toBePrinted.getWert();
  return os;
}
