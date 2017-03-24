#pragma once 
#include <TANamedObj.h>

struct TAPrimitive : public TANamedObj {
  TAPrimitive (const string & s) : TANamedObj(s) {}

  virtual const TAType & getType() const {
    return val.getType();
  }

  virtual TAValue & evaluate() {
    return val;
  }

  virtual void set(const TAValue & v) =0;
};
