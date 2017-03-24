#pragma once
#include <TANamedObj.h>
#include <TAArrayType.h>
#include <TAArrayValue.h>

struct TAArray : public TANamedObj {
  TAArrayType & type;

  TAArray(const string & name, const TAType & sub, unsigned int N) :
    TANamedObj(name), 
    type((TAArrayType&)TAType::getArrayTypeInstance(sub,N))
  {
    val.set(type);
  }

  virtual const TAType & getType() const {
    return type;
  }

  const TAType & getBaseType() const {
    return type.baseType;
  }
  unsigned int getCapacity () const {
    return type.cap;
  }

  virtual TAValue & evaluate() {
    return val;
  }

  virtual void printState(ostream & os) const {
    os << "(" << name << "," << type.cap << ",";
    val.print(os);
    os << ")";
  }

  virtual void setAt(TAValue & v, int idx) {
    val.getArrayValue().setAt(v,idx);
  }

};
