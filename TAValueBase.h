#pragma once
#include <TAValue.h>

struct TAValueBase : public TAObj {
  virtual bool isBool() const {return false;}
  virtual bool isInt() const {return false;}
  virtual bool isDouble() const {return false;}
  virtual bool isArray() const {return false;}
  virtual bool isPair() const {return false;}

  virtual bool getBool() const {throw 0; return false;}
  virtual int getInt() const {throw 0; return 0;}
  virtual double getDouble() const {throw 0; return 0.0;}
  virtual TAValue * getArray() const {throw 0; return 0;}
  virtual TAValue * getPair() const {throw 0; return 0;}

  virtual void setBool(bool v) { throw 1;}
  virtual void setInt(int v) {throw 1;}
  virtual void setDouble(double v) {throw 1;}
  virtual void set(const TAType & sub, unsigned int N) {throw 1;}

  virtual void setValue(const TAValue & v) = 0;
  virtual void print(ostream & os) const = 0;
  virtual TAValueBase * clone() const = 0;

// unary operations: object applies operation on op
//  and takes in result 
  virtual void assignUMinus(TAValue & op) {throw 3;}
  virtual void assignLNot(TAValue & op) {throw 3;}
  virtual void assignCeiling(TAValue & op) {throw 3;}
  virtual void assignFloor(TAValue & op) {throw 3;}

// binary operations: object applies operation on op1 and op2
//  and takes in result 
//  arithmetic ops
  virtual void assignPlus(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignMinus(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignProduct(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignDivision(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignRemainder(TAValue & op1, TAValue & op2) {throw 3;}

//  binary ops
//  arithmetic to boolean ops
  virtual void assignLessThan(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignLessThanEq(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignEqual(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignBiggerThan(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignBiggerThanEq(TAValue & op1, TAValue & op2) {throw 3;}

//  boolean ops
  virtual void assignLAnd(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignLOr(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignLEquiv(TAValue & op1, TAValue & op2) {throw 3;}
  virtual void assignLImplies(TAValue & op1, TAValue & op2) {throw 3;}

  // helper functions: int(int) --> bool, and double(double) --> bool
  virtual bool lessThan(TAValueBase & op) {throw 3; return false;}
  virtual bool lessThanEq(TAValueBase & op) { throw 3; return false;}
  virtual bool equal(TAValueBase & op) { throw 3; return false;}
  virtual bool biggerThan(TAValueBase & op) { throw 3; return false;}
  virtual bool biggerThanEq(TAValueBase & op) { throw 3; return false;}
};
