#include <TAType.h>
#include <TAIntType.h>
#include <TABoolType.h>
#include <TADoubleType.h>
#include <TAArrayType.h>
#include <TAPairType.h>

string TAType :: 
__getTypeString(unsigned int type) {
  static const char * types[TA_LAST] = {
    "", "bool", "int", "double", "array", "pair"};
  return types[type];
}
TAIntType TAIntType:: the; 
TABoolType TABoolType:: the;
TADoubleType TADoubleType:: the;


TAType & TAType :: 
getTypeInstance(unsigned int type) {
  switch(type) {
    case TA_BOOL: 
      return TABoolType :: the;
      break;
    case TA_INT:
      return TAIntType :: the;
      break;
    case TA_DOUBLE:
      return TADoubleType :: the;
      break;
    default:
      throw 1;
      break;
  }
  assert(0); // should never get here!
  return TAIntType :: the;
}

TAType & TAType :: 
getArrayTypeInstance(const TAType & sub, unsigned int N) {
  //TODO: hash these things. use getTypeNumber to do that
  TAArrayType * t = new TAArrayType(sub, N);
  return *t;
}

TAType & TAType :: 
getPairTypeInstance(const TAType & sub1, const TAType & sub2) {
  //TODO: hash these things. use getTypeNumber to do that
  TAPairType * t = new TAPairType(sub1, sub2);
  return *t;
}
