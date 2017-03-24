#pragma once
#include <TAPrimitive.h>

struct TADouble : public TAPrimitive {
  TADouble(const string & s) : TAPrimitive (s) {
    val.set(0.0);
  }

  virtual void printState(ostream & os) const {
    os << "(";
    list(os);
    os << "," << val.getDouble() << ")";
  }

  void set(double v) {
    val.set(v);
  }

  virtual void set(const TAValue & v) {
    val.set(v.getDouble());
  }
};
