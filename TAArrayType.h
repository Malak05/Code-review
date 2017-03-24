#pragma once
#include <TAType.h>
struct TAArrayType : public TAType {
  const TAType & baseType;
  unsigned int cap;

  TAArrayType(const TAType & sub, unsigned int N) : 
    baseType(sub), cap(N)
  {
    def.set(*this);
  }

//  virtual void setDefaultValue(TAValue & v) const {
//    v.set(*this);
//  }

  unsigned int getTypeNumber(const TAType & sub) const {
    return TA_ARRAY + 30*sub.getTypeNumber();
  }

  // the number is hashed and added to even types > TA_ARRAY are arrays of ... 
  virtual unsigned int getTypeNumber() const {
    return baseType.getTypeNumber();
  }

  virtual const string getTypeString() const {
    string str = baseType.getTypeString();
    return ".[" + str + "]";
  }
};

