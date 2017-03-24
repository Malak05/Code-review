#include <TAUnaryOp.h>

struct TAUMinus : public TAUnaryOp {
  TAUMinus(TATerm & op) : 
    TAUnaryOp(op) 
  {
    val.cloneBaseType(op.getValue());
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    val.assignUMinus(v);
    return val;
  }


  virtual const TAType & getType() const {
    // has the same type of its operand
    return getOperand().getType();
  };

  virtual const string operatorSign () const {
    return "-";
  }
};
