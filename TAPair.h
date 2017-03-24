#pragma once
#include <TANamedObj.h>
#include <TAPairType.h>

struct TAPair : public TANamedObj {
  TAPairType & type;

  TATerm &term1;
  TATerm &term2;

  TAPair (const string & name, TATerm & t1, TATerm & t2 ) :
    TANamedObj(name), 
    type((TAPairType&)TAType::getPairTypeInstance(t1.getType(), t2.getType())),
    term1(t1), term2(t2)
  {
//    val.set(type);
  }

  virtual const TAType & getType() const {
    return type;
  }

  virtual TAValue & evaluate() {
    return val;
  }

  virtual void printState(ostream & os) const {
    os << "<";
    term1.printState(os);
    os << ",";
    term2.printState(os);
    os << ">";
  }
};
