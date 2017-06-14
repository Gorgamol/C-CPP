#include "Bank.hpp"

Bank::~Bank() {
  konten.clear();
  std::cout << "Bank Destructor()" << std::endl;
}

void Bank::neuesKonto(std::string inhaber) {
  konten.push_back(std::unique_ptr<Konto>(new Konto(inhaber)));
}

void Bank::einzahlung(FixedPoint betrag, std::string inhaber) {
  for(auto& p : konten) {
    if((*(p)).inhaber == inhaber) {
      std::cout << "erfolg" << std::endl;
    }
  }
}
