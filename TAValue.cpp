#include <TAValue.h>
#include <TAValueBase.h>
#include <TABoolValue.h>
#include <TAIntValue.h>
#include <TADoubleValue.h>
#include <TAArrayValue.h>
#include <TAArrayType.h>

// int based constructor 
TAValue :: TAValue (int v) : 
   theValue( new TAIntValue(v))  
{
}

TAValue :: TAValue (bool v) : 
  theValue( new TABoolValue(v))  
{
}


TAValue :: TAValue (double v) : 
  theValue( new TADoubleValue(v))  
{
}

TAValue :: ~TAValue() {
  if (theValue) 
    delete theValue;
}

TAValueBase & 
TAValue :: getValue() const { 
  assert(theValue);
  return *theValue;
}

TAArrayValue & 
TAValue :: getArrayValue() const {
  assert(isArray());
  return (TAArrayValue & ) getValue();
}

const TAType & 
TAValue :: getType() const {
  return getValue().getType();
}

bool 
TAValue :: isBool() const {
  return getValue().isBool();
}

bool 
TAValue :: isInt() const {
  return getValue().isInt();
}

bool 
TAValue :: isDouble() const {
  return getValue().isDouble() ;
}

bool 
TAValue :: isArray() const {
  return getValue().isArray();
}

bool 
TAValue :: isPair() const {
  return getValue().isPair();
}

bool 
TAValue :: getBool() const {
  return getValue().getBool();
}


int 
TAValue :: getInt() const {
  return getValue().getInt();
}

double 
TAValue :: getDouble() const {
  return getValue().getDouble();
}

TAValue *
TAValue :: getArray() const {
  return getValue().getArray();
}

TAValue *
TAValue :: getPair() const {
  return getValue().getArray();
}

void 
TAValue :: set(int v) {
  if (!theValue) {
    theValue = new TAIntValue(v);
    return;
  }
  if (getValue().isInt()){
    getValue().setInt(v);
    return;
  }
  delete theValue;
  theValue = new TAIntValue(v);
}

void 
TAValue :: set(bool v) {
  if (!theValue) {
    theValue = new TABoolValue(v);
    return;
  }
  if (getValue().isBool()){
    getValue().setBool(v);
    return;
  }
  delete theValue;
  theValue = new TABoolValue(v);
}

void 
TAValue :: set(double v) {
  if (!theValue) {
    theValue = new TADoubleValue(v);
    return;
  }
  if (getValue().isDouble()){
    getValue().setDouble(v);
    return;
  }
  delete theValue;
  theValue = new TADoubleValue(v);
}

void 
TAValue :: set(const TAArrayType & t) {
  if (!theValue) {
    theValue = new TAArrayValue(t);
    return;
  }
}


void 
TAValue :: set(const TAValue & v) {
  if (!theValue) {
    cloneBaseType(v);
    return;
  }
  getValue().setValue(v);
}

void 
TAValue :: cloneBaseType(const TAValue & v) {
  theValue = v.getValue().clone();
}

void
TAValue :: print(ostream & os) const {
  getValue().print(os);
}

// unary operations: object applies operation on op
//  and takes in result 
TAValue &
TAValue :: assignUMinus(TAValue & op) {
  getValue().assignUMinus(op);
  return *this;
}

TAValue &
TAValue :: assignLNot(TAValue & op) {
  getValue().assignLNot(op);
  return *this;
}

TAValue &
TAValue :: assignCeiling(TAValue & op) {
  getValue().assignCeiling(op);
  return *this;
}

TAValue &
TAValue :: assignFloor(TAValue & op) {
  getValue().assignFloor(op);
  return *this;
}



// binary operations: object applies operation on op1 and op2
//  and takes in result 
//  arithmetic ops
TAValue &
TAValue :: assignPlus(TAValue & op1, TAValue & op2) {
  getValue().assignPlus(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignMinus(TAValue & op1, TAValue & op2) {
  getValue().assignMinus(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignProduct(TAValue & op1, TAValue & op2) {
  getValue().assignProduct(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignDivision(TAValue & op1, TAValue & op2) {
  getValue().assignDivision(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignRemainder(TAValue & op1, TAValue & op2) {
  getValue().assignRemainder(op1, op2);
  return *this;
}

TAValue & 
TAValue::assignSelect(TAValue & op1, TAValue & op2){
    int idx = op2.getInt();
    TAArrayValue & av = op1.getArrayValue();
    TAValue & vidx = av.values[idx];
    set(vidx);
}

//  binary ops
//  arithmetic to boolean ops
TAValue &
TAValue :: assignLessThan(TAValue & op1, TAValue & op2) {
  getValue().assignLessThan(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignLessThanEq(TAValue & op1, TAValue & op2) {
  getValue().assignLessThanEq(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignEqual(TAValue & op1, TAValue & op2) {
  getValue().assignEqual(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignBiggerThan(TAValue & op1, TAValue & op2) {
  getValue().assignBiggerThan(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignBiggerThanEq(TAValue & op1, TAValue & op2) {
  getValue().assignBiggerThanEq(op1, op2);
  return *this;
}


//  boolean ops
TAValue &
TAValue :: assignLAnd(TAValue & op1, TAValue & op2) {
  getValue().assignLAnd(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignLOr(TAValue & op1, TAValue & op2) {
  getValue().assignLOr(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignEquiv(TAValue & op1, TAValue & op2) {
  getValue().assignLEquiv(op1, op2);
  return *this;
}

TAValue &
TAValue :: assignImplies(TAValue & op1, TAValue & op2) {
  getValue().assignLImplies(op1, op2);
  return *this;
}
