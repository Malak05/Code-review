#pragma once 
#include <TAUnaryOp.h>
#include <TAArray.h>

struct TASize : public TAUnaryOp {

  TASize (TAArray & a) : 
    TAUnaryOp (a)
  {
    val.set((int)getArray().getCapacity());
  }

  TAArray & getArray() const {
    return (TAArray &) getOperand();
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    return val;
  }

  virtual const TAType & getType() const {
    return TAType::getTypeInstance(TA_INT);
  }

  virtual const string operatorSign () const {
    return "size";
  }
};
