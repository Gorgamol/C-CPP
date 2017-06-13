#ifndef BARGELD_H
#define BARGELD_H

#include "FixedPoint.hpp"
#include <iostream>

class Bargeld {

public:
  Bargeld(float wert);
  virtual ~Bargeld() = 0; //pure Virtual damit base klasse nicht instanziert wird

  FixedPoint getWert(void) const;
  FixedPoint operator+(const Bargeld &b) const;

private:
  FixedPoint wert;
};

class Bargeld_Schein : public Bargeld {

public:
  Bargeld_Schein(float wert, int seriennummer);
  virtual ~Bargeld_Schein();

  int getSeriennummer(void); //dynamic_cast<Bargeld_Schein*>

private:
  int seriennummer;
};

class Bargeld_Muenze : public Bargeld {

public:
  Bargeld_Muenze(float wert);
  virtual ~Bargeld_Muenze();
};

std::ostream& operator << (std::ostream& os, const Bargeld& toBePrinted);

#endif
