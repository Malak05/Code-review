#pragma once
#include <TAValueBase.h>
#include <TAArrayType.h>

struct TAArrayValue : public TAValueBase {
  const TAArrayType & type;
  TAValue *values; 

  TAArrayValue(const TAArrayType & t) :
    type(t)
  {
    initValuesArray();
  }
  void initValuesArray() {
    values = new TAValue[type.cap];
    for(int i =0; i < type.cap; i++) {
      const TAValue & def = type.baseType.getDefaultValue();
      values[i].set(def);
    }
  }

  virtual const TAType & getType() const {
    return type;
  }

  virtual void set(TAValue * vs ) {
    for(int i =0; i < type.cap; i++) {
      values[i].set(vs[i]);
    }
  }

  virtual void setAt(TAValue & v, int idx) {
    assert(0 <= idx);
    assert(idx < type.cap);
    values[idx].set(v);
  }

  virtual bool isArray() const {return true;}
  virtual TAValue * getArray() const {return values;}

  virtual void setValue(const TAValue & v) {
    assert(v.isArray());

    TAValue * vs = v.getArray();
    set(vs);
  }

  virtual void print(ostream & os) const {
    for(int i=0; i< type.cap; i++){
      values[i].print(os);
      os << " ";
    }
  }
  virtual TAValueBase * clone() const {
    TAArrayValue * val = new TAArrayValue(type);
    return val;
  }

};
