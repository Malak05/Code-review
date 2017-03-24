#include <TABinaryOp.h>

struct TAMinus : public TABinaryOp {
  TAMinus(TATerm & op1, TATerm & op2) : 
    TABinaryOp(op1,op2) 
  {
    val.cloneBaseType(op1.getValue());
  }

  virtual TAValue & evaluateExecute(TAValue & val1, TAValue & val2) {
    val.assignMinus(val1,val2);
    return val;
  }


  virtual const TAType & getType() const {
    // has the same type of its operand
    return getLeft().getType();
  };

  virtual const string operatorSign () const {
    return "-";
  }
};
