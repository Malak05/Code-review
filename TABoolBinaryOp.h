#pragma once 
#include <TABinaryOp.h>

struct TABoolBinaryOp : public TABinaryOp {

  TABoolBinaryOp(TATerm & op1, TATerm & op2) :
    TABinaryOp(op1, op2) 
  {
    val.set(false);
  }
  virtual const TAType & getType() const {
    // this is a formula, it returns a boolean type
    return TAType::getTypeInstance(TA_BOOL);
  };

};
