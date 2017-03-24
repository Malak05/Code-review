#pragma once 

#include <TAObj.h>
#include <TAValue.h>
#include <iostream>
using namespace std;

class TAValue;

struct TATerm : public TAObj {
  TAValue val;

  void list() const {
    list(cout);
  }

  virtual void printState() const {
    printState(cout);
  }

  virtual const TAValue & getValue() const {
    return val;
  }

  virtual void list( ostream & os) const = 0;
  virtual TAValue & evaluate() =0;
  virtual void printState(ostream & os) const {
    val.print(os);
  }
}; 

