#include <TAUnaryOp.h>

struct TASecond : public TAUnaryOp {
  TASecond (TAPair & pair) : 
    TAUnaryOp(pair) 
  {
  }

  virtual TAPair & getPair() const {
    return (TAPair&) getOperand();
  }

  virtual TAValue & evaluateExecute(TAValue & v) {
    return getPair().term2.evaluate();
  }

  virtual void printState(ostream & os) const {
    getPair().term2.printState(os);
  }

  virtual const TAType & getType() const {
    return getPair().term2.getType();
  };

  virtual const string operatorSign () const {
    return "second";
  }
};
