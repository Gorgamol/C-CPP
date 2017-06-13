#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <iostream>

struct FixedPoint {
  int lHs_number;
  int rHs_number;
  FixedPoint(float number);
  FixedPoint operator+(const FixedPoint &b) const;
  FixedPoint operator-(const FixedPoint &b) const;
};

std::ostream& operator << (std::ostream& os, const FixedPoint& toBePrinted);

#endif
