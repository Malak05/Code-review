#pragma once
#include <TAType.h>
#include <TAValue.h>

struct TAIntType : public TAType {
  TAIntType() {def.set(0);}

  virtual unsigned int getTypeNumber() const {
    return TA_INT;
  }
  virtual const string getTypeString() const {
    return "int"; 
  }

//  virtual void setDefaultValue(TAValue & v) const {
//    v.set(0);
//  }

  // not a forced singleton 
  static TAIntType the; 
};
