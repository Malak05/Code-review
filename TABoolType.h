#pragma once
#include <TAType.h>

struct TABoolType : public TAType {
  TABoolType() {def.set(false);}

  virtual unsigned int getTypeNumber() const {
    return TA_BOOL;
  }
  virtual const string getTypeString() const {
    return "bool"; 
  }
  static TABoolType the;
};
