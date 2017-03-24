#pragma once 
#include <TATerm.h>

struct TAUnaryOp : public TATerm {
  TATerm & operand;

  TAUnaryOp(TATerm & op) :
    operand(op)
  {
  }

  TATerm & getOperand() const {return operand;}

  virtual TAValue & evaluate() {
    TAValue & val = getOperand().evaluate();
    return evaluateExecute(val);
  }

  virtual void list( ostream & os) const {
    os << "(" << operatorSign() << " ";
    getOperand().list(os);
    os << ")";
  }

  virtual const string operatorSign () const =0;

  virtual TAValue & evaluateExecute(TAValue & val) = 0;
};
