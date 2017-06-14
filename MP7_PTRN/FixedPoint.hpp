#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <iostream>

struct FixedPoint {
  int lHs_number;
  int rHs_number;
  bool negative;
  FixedPoint(float number);
  FixedPoint operator+(const FixedPoint &b) const;
  FixedPoint operator-(const FixedPoint &b) const;
  bool operator==(const FixedPoint &b) const;
};

std::ostream& operator << (std::ostream& os, const FixedPoint& toBePrinted);

#endif
