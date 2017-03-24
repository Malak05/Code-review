#pragma once
#include <TAType.h>
struct TADoubleType : public TAType {

  TADoubleType () {def.set(0.0);}

  virtual unsigned int getTypeNumber() const {
    return TA_DOUBLE;
  }
  virtual const string getTypeString() const {
    return "double"; 
  }
//  virtual void setDefaultValue(TAValue & v) const {
//    v.set(0.0);
//  }
  static TADoubleType the;
};

