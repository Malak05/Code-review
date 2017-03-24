#include <TABinaryOp.h>

struct TAPlus : public TABinaryOp {
  TAPlus(TATerm & op1, TATerm & op2) : 
    TABinaryOp(op1,op2) 
  {
    val.cloneBaseType(op1.getValue());
  }
  virtual TAValue & evaluateExecute(TAValue & val1, TAValue & val2) {
    val.assignPlus(val1,val2);
    return val;
  }


  virtual const TAType & getType() const {
    // plus has the same type of its operands
    return getLeft().getType();
  };

  virtual const string operatorSign () const {
    return "+";
  }
};
