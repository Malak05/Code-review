#pragma once
#include <TAType.h>
struct TAPairType : public TAType {

  const TAType & baseType1;
  const TAType & baseType2;

  TAPairType(const TAType & sub1, const TAType & sub2) : 
    baseType1(sub1), baseType2(sub2) 
  {
  }

  unsigned int getTypeNumber(const TAType & sub1, const TAType & sub2) const {
    return TA_PAIR +50*sub1.getTypeNumber() + 70 *sub2.getTypeNumber();

  }

  // hash generate a type number
  virtual unsigned int getTypeNumber () const {
    return getTypeNumber(baseType1, baseType2);
  }

  virtual const string getTypeString() const {
    string str1 = baseType1.getTypeString();
    string str2 = baseType2.getTypeString();
    return "<" + str1 + "," + str2 + ">";
  }
};
