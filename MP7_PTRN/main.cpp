#include <iostream>
#include "FixedPoint.hpp"
#include "Bargeld.hpp"
#include "Bank.hpp"
#include "Konto.hpp"
#include <memory>


int main() {

  /*std::vector<std::unique_ptr<Bargeld>> test;
  std::vector<std::unique_ptr<Bargeld>> test2;
  //std::unique_ptr<Bargeld> p1(new Bargeld_Muenze(5));
  //std::unique_ptr<Bargeld> p2(new Bargeld_Muenze(5));
  test.push_back(std::unique_ptr<Bargeld> (new Bargeld_Muenze(5)));
  test.push_back(std::unique_ptr<Bargeld> (new Bargeld_Muenze(5)));


  std::cout << "test1" << test.size() << std::endl;
  for(auto& p : test) {
    std::cout << (*(p)) << std::endl;
   }
  std::cout << "test2" << test2.size() << std::endl;
  for(auto& p : test2) {
    std::cout << (*(p)) << std::endl;
   }
  test2.push_back(std::move(test.at(1)));
  test.erase(test.begin() + 1);
  std::cout << "test1" << test.size() << std::endl;
  for(auto& p : test) {
    std::cout << (*(p)) << std::endl;
   }
  std::cout << "test2" << test2.size() << std::endl;
  for(auto& p : test2) {
    std::cout << (*(p)) << std::endl;
  }*/

  Bank bank;
  bank.neuesKonto("Test");
  bank.einzahlung(20.05, "Test");
  return 0;
}
