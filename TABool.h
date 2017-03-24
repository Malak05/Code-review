#pragma once
#include <TAPrimitive.h>

struct TABool : public TAPrimitive {
  TABool (const string & s) : TAPrimitive (s) {
    val.set(false);
  }

  virtual void printState(ostream & os) const {
    os << "(";
    list(os);
    os << "," << val.getBool() << ")";
  }

  void set(bool v) {
    val.set(v);
  }

  virtual void set(const TAValue & v) {
    val.set(v.getBool());
  }
};
