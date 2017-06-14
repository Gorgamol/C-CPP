#include "FixedPoint.hpp"

FixedPoint::FixedPoint(float number) : lHs_number(number) , rHs_number((number * 100) - (lHs_number * 100)), negative(false) {
  if(rHs_number < 0) {
    rHs_number = rHs_number * (-1);
    negative = true;
  }
  if(lHs_number < 0) {
    lHs_number = lHs_number * (-1);
    negative = true;
  }
}

FixedPoint FixedPoint::operator+(const FixedPoint &b) const {
  float result = this->rHs_number + b.rHs_number;
  result = result / 100;
  result = result + this->lHs_number + b.lHs_number;
  return result;
}

FixedPoint FixedPoint::operator-(const FixedPoint &b) const {
  float result = this->rHs_number - b.rHs_number;
  result = result / 100;
  result = result + (this->lHs_number - b.lHs_number);
  return result;
}

  bool FixedPoint::operator==(const FixedPoint &b) const {
    if((this->lHs_number == b.lHs_number) && (this->rHs_number == b.rHs_number) && (this->negative == b.negative)) {
      return true;
    }
    return false;
  }

std::ostream& operator << (std::ostream& os, const FixedPoint& toBePrinted) {
  if(toBePrinted.rHs_number == 0) {
    if(toBePrinted.negative == false) {
      os << toBePrinted.lHs_number << ",00";
    } else {
      os << '-' << toBePrinted.lHs_number << ",00";
    }
  } else if(toBePrinted.rHs_number / 10 == 0){
    if(toBePrinted.negative == false) {
      os << toBePrinted.lHs_number << ",0" << toBePrinted.rHs_number;
    } else {
      os << '-' << toBePrinted.lHs_number << ",0" << toBePrinted.rHs_number;
    }
  } else {
    if(toBePrinted.negative == false) {
      os << toBePrinted.lHs_number << ',' << toBePrinted.rHs_number;
    } else {
      os << '-' << toBePrinted.lHs_number << ',' << toBePrinted.rHs_number;
    }
  }
  return os;
}
