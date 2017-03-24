#pragma once
#include <TAObj.h>
#include <iostream>
using namespace std;

class TAType;
class TAValueBase; 
class TAArrayValue; 
class TAArrayType;

// self encapsulating object
// wrapper 
// and potentially adapter 
struct TAValue : public TAObj { 
  TAValueBase * theValue;

  // the following constructors also work as cast operators
  // int based constructor 
  TAValue (int v);
  TAValue (bool v);
  TAValue (double v);
  TAValue() : theValue(0) {}

  ~TAValue();

  //provides a prettier reference interface to theValue
  TAValueBase & getValue() const;
  TAArrayValue & getArrayValue() const;

  virtual const TAType & getType() const;

  virtual bool isBool() const ;
  virtual bool isInt() const ;
  virtual bool isDouble() const ;
  virtual bool isArray() const ;
  virtual bool isPair() const ;

  virtual bool getBool() const ;
  virtual int getInt() const ;
  virtual double getDouble() const ;
  virtual TAValue * getArray() const ;
  virtual TAValue * getPair() const ;

  virtual void set(bool v) ;
  virtual void set(int v) ;
  virtual void set(double v) ;
//  virtual void set(TAValue * vs, unsigned int N);
  virtual void set(const TAArrayType & t);

  virtual void set(const TAValue & v) ;
  virtual void cloneBaseType(const TAValue & v);
  virtual void print(ostream & os) const;


// unary operations: object applies operation on op
//  and takes in result 
  virtual TAValue & assignUMinus(TAValue & op);
  virtual TAValue & assignLNot(TAValue & op);
  virtual TAValue & assignCeiling(TAValue & op);
  virtual TAValue & assignFloor(TAValue & op);

// binary operations: object applies operation on op1 and op2
//  and takes in result 
//  arithmetic ops
  virtual TAValue & assignPlus(TAValue & op1, TAValue & op2);
  virtual TAValue & assignMinus(TAValue & op1, TAValue & op2);
  virtual TAValue & assignProduct(TAValue & op1, TAValue & op2);
  virtual TAValue & assignDivision(TAValue & op1, TAValue & op2);
  virtual TAValue & assignRemainder(TAValue & op1, TAValue & op2);
  virtual TAValue & assignSelect(TAValue & op1, TAValue & op2);

//  binary ops
//  arithmetic to boolean ops
  virtual TAValue & assignLessThan(TAValue & op1, TAValue & op2);
  virtual TAValue & assignLessThanEq(TAValue & op1, TAValue & op2);
  virtual TAValue & assignEqual(TAValue & op1, TAValue & op2);
  virtual TAValue & assignBiggerThan(TAValue & op1, TAValue & op2);
  virtual TAValue & assignBiggerThanEq(TAValue & op1, TAValue & op2);

//  boolean ops
  virtual TAValue & assignLAnd(TAValue & op1, TAValue & op2);
  virtual TAValue & assignLOr(TAValue & op1, TAValue & op2);
  virtual TAValue & assignEquiv(TAValue & op1, TAValue & op2);
  virtual TAValue & assignImplies(TAValue & op1, TAValue & op2);
};

