#include <iostream> 
#include <ta.h>
using namespace std;

int
main(int argc, char ** argv) {

  cout << "welcome to the type architecture program." << endl;

  cout << "declaring and setting primitive variable." << endl;
  TAInt x("x");
  x.printState(cout);
  x.set(5);
  x.printState(cout);

  TABool b("b");
  b.printState(cout);
  b.set(true);
  b.printState(cout);

  TADouble d("d");
  d.printState(cout);
  d.set(0.5);
  // d.printState(); 

  TAInt y("y");
  y.printState(cout);
  y.set(5);
  y.printState(cout);

  cout << endl;
  cout << "declaring and evaluating operations." << endl;
  cout << "x+y" << endl;
  TAPlus n1(x,y);
  n1.evaluate();
  n1.printState(cout);

  cout << endl;
  cout << "x-y" << endl;
  TAMinus n2(x,y);
  n2.evaluate();
  n2.printState(cout);

  cout << endl;
  cout << "x*(x+y)" << endl;
  TAProduct n3(n1,x);
  n3.evaluate();
  n3.printState(cout);

  cout << endl;
  cout << "x*(x+y)/x" << endl;
  TADivision n4(n3,x);
  n4.evaluate();
  n4.printState(cout);

  cout << endl;
  cout << "x*(x+y) remainder x" << endl;
  TARemainder n5(n3,x);
  n5.evaluate();
  n5.printState(cout);
  
  cout << endl;
  cout << "listing x*(x+y) remainder x" << endl;
  n5.list(cout);
  cout << endl;

  cout << endl;
  cout << "More " << endl;
  TALessThan n6(x,y);
  TALessThanEq n7(x,y);
  TABiggerThan n8(x,y);
  TABiggerThanEq n9(x,y);
  TAEqual n10(x,y);

  TALAnd n11(b,n6);
  TALOr n12(n7,n8);
  TAEquiv n13(n9,n10);
  TAImplies n14(n12,n13);

  n11.list(cout);
  n11.evaluate();
  n11.printState(cout);
  cout << endl;

  n14.evaluate();
  n14.list(cout);
  n14.printState(cout);
  cout << endl;

  n13.list(cout);
  cout << endl;

  TAUMinus n15 (n1); // -(x+y)
  n15.evaluate();
  n15.list(cout);
  n15.printState(cout);
  cout << endl;

  d.set(2.5);
  d.printState(cout);

  TACeiling c(d);
  TAFloor f(d);
  c.evaluate();
  f.evaluate();

  c.list(cout);
  c.printState(cout);
  cout << endl;

  f.list(cout);
  f.printState(cout);
  cout << endl;

  cout << "playing with arrays "<<endl;
  TAArray a("a", x.getType(), 16);
  TAArray aa("aa", a.getType(), 2);
  TASize sz(a);

  cout << "array initially"<<endl;
  a.printState(cout);
  cout <<endl;

  cout << "array size" << endl;
  sz.printState(cout);
  cout << endl;

  cout << "array access, setting array at index x to y" << endl;
  x.set(1);
  x.printState(cout);
  cout << endl;

  TAArrayAccess a1(a,x);
  a1.set(y);
  a1.list(cout);
  a1.printState(cout);
  cout << endl;
  cout << "array after set"<<endl;
  a.printState(cout);
  cout <<endl;

  cout << "reading the set index with another access" << endl;
  TAArrayAccess a2(a,x);
  a2.evaluate();
  a2.printState(cout);

  cout << "playing with pairs" << endl;
  TAPair p("p", x, d);
  p.list(cout);
  cout << endl;

  TAFirst p1(p);
  p1.list(cout);
  p1.printState(cout);
  cout << endl;

  TASecond p2(p);
  p2.list(cout);
  p2.printState(cout);

  cout << endl;
  cout << "the type architecture program is exiting gracefully." << endl;

  return 0;
}
