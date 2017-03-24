#pragma once
#include <TAValueBase.h>

struct TADoubleValue : public TAValueBase {
  double dValue;

  TADoubleValue (double v) : dValue(v){}

  virtual bool isDouble() const {return true;}

  virtual double getDouble() const {return dValue;}

  void setValue(const TAValue & v) {
    dValue = v.getDouble();
  }

  virtual void setDouble (double v) { dValue = v;}

  virtual const TAType & getType() const {
    return TAType::getTypeInstance(TA_DOUBLE);
  }

  virtual void print(ostream & os) const {
    os << dValue;
  }

  virtual TAValueBase * clone() const {
    return new TADoubleValue(dValue);
  }

// unary operations: object applies operation on op
//  and takes in result 
  virtual void assignUMinus(TAValue & op) {
    dValue = -op.getValue().getDouble();
  }

// binary operations: object applies operation on op1 and op2
//  and takes in result 
//  arithmetic ops
  virtual void assignPlus(TAValue & op1, TAValue & op2) {
    dValue = op1.getValue().getDouble() + op2.getValue().getDouble();
  }
  virtual void assignMinus(TAValue & op1, TAValue & op2) {
    dValue = op1.getValue().getDouble() - op2.getValue().getDouble();
  }
  virtual void assignProduct(TAValue & op1, TAValue & op2) {
    dValue = op1.getValue().getDouble() * op2.getValue().getDouble();
  }
  virtual void assignDivision(TAValue & op1, TAValue & op2) {
    dValue = op1.getValue().getDouble() / op2.getValue().getDouble();
  }
//  virtual void assignRemainder(TAValue & op1, TAValue & op2) {
//    dValue = op1.getValue().getDouble() % op2.getValue().getInt();
//  }

//  binary ops
//  arithmetic to boolean ops
  virtual bool lessThan(TAValue & op) {
    return dValue < op.getValue().getDouble();
  }
  virtual bool lessThanEq(TAValue & op) {
    return dValue <= op.getValue().getDouble();
  }
  virtual bool equal(TAValue & op) {
    return dValue == op.getValue().getDouble();
  }
  virtual bool biggerThan(TAValue & op) {
    return dValue > op.getValue().getDouble();
  }
  virtual bool biggerThanEq(TAValue & op) {
    return dValue >= op.getValue().getDouble();
  }
};

