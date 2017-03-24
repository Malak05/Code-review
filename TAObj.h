#pragma once 
#include <assert.h> // used for calls to assert function

class TAType;

struct TAObj {
  unsigned int id; // each object has a unique id. 

  TAObj() : id(_idCounter++) {}

  virtual const TAType & getType() const = 0;
  unsigned int getId() const {return id;}

  static unsigned int _idCounter; 

};
