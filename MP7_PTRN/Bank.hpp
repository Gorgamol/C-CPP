#ifndef BANK_H
#define BANK_H

#include "Konto.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include "FixedPoint.hpp"


class Bank {
public:
  void neuesKonto(std::string inhaber);
  void einzahlung(FixedPoint betrag, std::string inhaber);
  ~Bank();
private:
  std::vector<std::unique_ptr<Konto>> konten;
};

#endif
