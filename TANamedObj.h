#pragma once 
#include <TATerm.h>
#include <string> 
using namespace std; 

struct TANamedObj : public TATerm {
  string name; 

  TANamedObj() {}

  TANamedObj(const string & s) : name(s) {
  }

  virtual void list( ostream & os) const {
    os << name;
  }
};
