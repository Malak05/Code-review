#pragma once 
#include <TATerm.h>

struct TABinaryOp : public TATerm {
  TATerm & operand1;
  TATerm & operand2;

  TABinaryOp(TATerm & op1, TATerm & op2) :
    operand1(op1), operand2(op2) 
  {
  }

  TATerm & getLeft() const {return operand1;}
  TATerm & getRight() const {return operand2;}

  virtual TAValue & evaluate() {
    TAValue & val1 = getLeft().evaluate();
    TAValue & val2 = getRight().evaluate();
    return evaluateExecute(val1,val2);
  }

  virtual void list( ostream & os) const {
    os << "(" << operatorSign() << " ";
    getLeft().list(os);
    os << " ";
    getRight().list(os);
    os << ")";
  }

  virtual const string operatorSign () const =0;

  virtual TAValue & evaluateExecute(TAValue & val1, TAValue & val2) = 0;
};
