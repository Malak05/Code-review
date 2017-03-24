#include <TAUnaryOp.h>

struct TALNot : public TAUnaryOp {
  TALNot (TATerm & op) : 
    TAUnaryOp(op) 
  {
    val.set(false);
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    val.assignLNot(v);
    return val;
  }


  virtual const TAType & getType() const {
    // has the same type of its operand
    return getOperand().getType();
  };

  virtual const string operatorSign () const {
    return "!";
  }
};
