#pragma once
#include <TAPrimitive.h>

struct TAInt : public TAPrimitive {

  TAInt(const string & s) : TAPrimitive (s) {
    val.set(0);
  }

  virtual void printState(ostream & os) const {
    os << "(";
    list(os);
    os << "," << val.getInt() << ")";
  }

  void set(int v) {
    val.set(v);
  }

  virtual void set(const TAValue & v) {
    val.set(v.getInt());
  }
};
