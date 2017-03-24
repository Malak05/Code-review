#include <TAUnaryOp.h>

struct TAFirst : public TAUnaryOp {
  TAFirst (TAPair & pair) : 
    TAUnaryOp(pair) 
  {
  }

  virtual TAPair & getPair() const {
    return (TAPair&) getOperand();
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    return getPair().term1.evaluate();
  }

  virtual void printState(ostream & os) const {
    getPair().term1.printState(os);
  }

  virtual const TAType & getType() const {
    return getPair().term1.getType();
  };

  virtual const string operatorSign () const {
    return "first";
  }
};
