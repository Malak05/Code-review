#pragma once 
#include <TAValueBase.h>


struct TAIntValue : public TAValueBase {
  int iValue;

  TAIntValue (int v) : iValue(v){}

  virtual bool isInt() const {return true;}
  virtual int getInt() const {return iValue;}

  virtual void setValue(const TAValue & v) {
    assert(v.isInt());
    iValue = v.getInt();
  }

  virtual const TAType & getType() const {
    return TAType::getTypeInstance(TA_INT);
  }
  virtual void setInt(int v) { iValue = v;}
// unary operations: object applies operation on op
//  and takes in result 
  virtual void assignUMinus(TAValue & op) {
    iValue = -op.getValue().getInt();
  }
  virtual void assignCeiling(TAValue & op) {
    //TODO: this should be fixed later
    iValue = op.getValue().getDouble() + 1;
  }
  virtual void assignFloor(TAValue & op) {
    iValue = op.getValue().getDouble();
  }

  virtual void print(ostream & os) const {
    os << iValue;
  }

  virtual TAValueBase * clone() const {
    return new TAIntValue(iValue);
  }

// binary operations: object applies operation on op1 and op2
//  and takes in result 
//  arithmetic ops
  virtual void assignPlus(TAValue & op1, TAValue & op2) {
    iValue = op1.getValue().getInt() + op2.getValue().getInt();
  }
  virtual void assignMinus(TAValue & op1, TAValue & op2) {
    iValue = op1.getValue().getInt() - op2.getValue().getInt();
  }
  virtual void assignProduct(TAValue & op1, TAValue & op2) {
    iValue = op1.getValue().getInt() * op2.getValue().getInt();
  }
  virtual void assignDivision(TAValue & op1, TAValue & op2) {
    iValue = op1.getValue().getInt() / op2.getValue().getInt();
  }
  virtual void assignRemainder(TAValue & op1, TAValue & op2) {
    iValue = op1.getValue().getInt() % op2.getValue().getInt();
  }

//  binary ops
//  arithmetic to boolean ops
  virtual bool lessThan(TAValueBase & op) {
    return iValue < op.getInt();
  }
  virtual bool lessThanEq(TAValueBase & op) {
    return iValue <= op.getInt();
  }
  virtual bool equal(TAValueBase & op) {
    return iValue == op.getInt();
  }
  virtual bool biggerThan(TAValueBase & op) {
    return iValue > op.getInt();
  }
  virtual bool biggerThanEq(TAValueBase & op) {
    return iValue >= op.getInt();
  }
};
