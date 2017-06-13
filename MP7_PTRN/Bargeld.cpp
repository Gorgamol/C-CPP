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

Bargeld_Schein::Bargeld_Schein(float wert, int seriennummer) : Bargeld(wert), seriennummer(seriennummer) {

}

Bargeld_Schein::~Bargeld_Schein() {

}

int Bargeld_Schein::getSeriennummer(void) {
  return seriennummer;
}

Bargeld_Muenze::Bargeld_Muenze(float wert) : Bargeld(wert) {

}

Bargeld_Muenze::~Bargeld_Muenze() {

}

std::ostream& operator << (std::ostream& os, const Bargeld& toBePrinted) {
  os << toBePrinted.getWert();
  return os;
}
