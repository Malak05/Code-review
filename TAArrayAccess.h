#pragma once
#include <TABinaryOp.h>
#include <TAArray.h>

struct TAArrayAccess : public TABinaryOp {

  TAArrayAccess (TAArray & a, TATerm & t) :
    TABinaryOp(a,t) 
  {
    //use the subtype of `a' to select a default value
    val.set(a.getBaseType().getDefaultValue());
  }

  TAArray & getArray() const {
    return (TAArray&)getLeft();
  }

  virtual const TAType & getType() const {
    return getArray().getBaseType();
  }

  virtual TAValue & evaluateExecute(TAValue & val1, TAValue & val2) {
    // val1 is an array value, 
    // val2 is an expression value
    val.assignSelect(val1,val2);
    return val;
  }

  virtual void set(TATerm & t) {
    TAValue & v = t.evaluate();
    val.set(v);

    TAValue & idx = getRight().evaluate();
    int iidx = idx.getInt();
    getArray().setAt(val,iidx);
  }

  virtual const string operatorSign () const {
    return "select";
  }
};
