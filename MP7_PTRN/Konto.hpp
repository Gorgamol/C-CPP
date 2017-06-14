#ifndef KONTO_H
#define KONTO_H

#include <iostream>
#include <vector>
#include <memory>
#include "Bargeld.hpp"

struct Konto {
public:
  Konto(std::string inhaber);
  ~Konto();
  std::string inhaber;
  std::vector<std::unique_ptr<Bargeld>> kontostand;
};

#endif
