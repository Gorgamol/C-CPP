#include "FixedPoint.hpp"

FixedPoint::FixedPoint(float number) {
  lHs_number = number;
  rHs_number = (number * 100) - (lHs_number * 100);
}

FixedPoint FixedPoint::operator+(const FixedPoint &b) const {
  float result = (this->rHs_number + b.rHs_number) / 100;
  result += (this->lHs_number + b.lHs_number);
  return result;
}

FixedPoint FixedPoint::operator-(const FixedPoint &b) const {

}

std::ostream& operator << (std::ostream& os, const FixedPoint& toBePrinted) {
  if(toBePrinted.rHs_number == 0) {
    os << toBePrinted.lHs_number << ",00";
  } else if(toBePrinted.rHs_number / 10 == 0){
    os << toBePrinted.lHs_number << ",0" << toBePrinted.rHs_number;
  } else {
    os << toBePrinted.lHs_number << ',' << toBePrinted.rHs_number;
  }
  return os;
}
