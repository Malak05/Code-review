#pragma once 
#include <TAValueBase.h>
#include <TAType.h>

struct TABoolValue : public TAValueBase {
  bool bValue;

  TABoolValue(bool b) : bValue(b){}

  virtual bool isBool() const {return true;}
  virtual bool getBool() const {return bValue;}

  virtual const TAType & getType() const {
    return TAType::getTypeInstance(TA_BOOL);
  }

  virtual void setValue(const TAValue & v) {
    bValue = v.getBool();
  }

  virtual void setBool(bool v) { bValue = v;}

  virtual TAValueBase * clone() const {
    return new TABoolValue(bValue);
  }

  virtual void print(ostream & os) const {
    os << (bValue? "true" : "false");
  }
// operations 
  virtual void assignLNot(TAValue & op) {
    bValue = !op.getValue().getBool();
  }
// arithmetic to boolean
  virtual void assignLessThan(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().lessThan(op2.getValue());
  }

  virtual void assignLessThanEq(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().lessThanEq(op2.getValue());
  }

  virtual void assignEqual(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().equal(op2.getValue());
  }
  virtual void assignBiggerThan(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().biggerThan(op2.getValue());
  }
  virtual void assignBiggerThanEq(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().biggerThanEq(op2.getValue());
  }

//  boolean ops
  virtual void assignLAnd(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().getBool() && op2.getValue().getBool();
  }
  virtual void assignLOr(TAValue & op1, TAValue & op2) {
    bValue = op1.getValue().getBool() || op2.getValue().getBool();
  }

  virtual void assignLEquiv(TAValue & op1, TAValue & op2) {
    bool b1 = op1.getValue().getBool();
    bool b2 = op2.getValue().getBool();
    bValue = (b1 == b2);
  }
  virtual void assignLImplies(TAValue & op1, TAValue & op2) {
    bool b1 = op1.getValue().getBool();
    bool b2 = op2.getValue().getBool();
    bValue = ( (!b1) || b2);
  }
};
