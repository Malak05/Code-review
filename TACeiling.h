#pragma once 
#include <TAUnaryOp.h>

struct TACeiling : public TAUnaryOp {
  TACeiling (TATerm & op) : 
    TAUnaryOp(op) 
  {
    val.set(0);
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    val.assignCeiling(v);
    return val;
  }

  virtual const TAType & getType() const {
    return TAType::getTypeInstance(TA_INT);
  };

  virtual const string operatorSign () const {
    return "ceiling";
  }
};
