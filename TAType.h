#pragma once
#include <TAObj.h>
#include <TAValue.h>
#include <string>

using namespace std;

typedef enum {
  TA_NONE, 
  TA_BOOL, TA_INT, TA_DOUBLE, TA_ARRAY, TA_PAIR, TA_LAST
} TAType_em;


struct TAType : public TAObj {
  TAValue def;

  virtual unsigned int getTypeNumber () const = 0;
  virtual const TAType & getType() const {
    return *this;
  }
  virtual const string getTypeString() const = 0;
//  virtual void setDefaultValue(TAValue & v) const = 0;

  virtual const TAValue & getDefaultValue() const {return def;}

  static string __getTypeString(unsigned int type);

  // interface to the singleton objects
  static TAType & getTypeInstance(unsigned int type);
  static TAType & getArrayTypeInstance(const TAType & sub, unsigned int N);
  static TAType & getPairTypeInstance(const TAType & sub1, const TAType & sub2);
}; 
