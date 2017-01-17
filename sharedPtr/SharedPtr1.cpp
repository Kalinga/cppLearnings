// shared_ptr constructor example
#include <iostream>
#include <tr1/memory>

struct C {int* data;};

class Test {
public:
  Test () {std::cout << "Test()" << '\n';}
  ~Test () {std::cout << "~Test()" << '\n';}
};

int main () {
  std::tr1::shared_ptr<Test> p1(new Test);

  int *intPtr = new int;
  std::cout << "intPtr: " << intPtr << '\n';
  *intPtr = 65;
  std::cout << "*intPtr: " << *intPtr << '\n';

  std::tr1::shared_ptr<int> p2 (new int);

  std::tr1::shared_ptr<int> p3 (new int);
  
  std::tr1::shared_ptr<int> p4 (intPtr);
  std::tr1::shared_ptr<int> p5 (p4);
  

//  p1 = p3;  cannot convert ‘int* const’ to ‘Test*’ in assignment

  std::cout << "use_count:\n";
  std::cout << "p1: " << p1.use_count() << '\n';
  std::cout << "p2: " << p2.use_count() << '\n';
  std::cout << "p3: " << p3.use_count() << '\n';
  std::cout << "p4: " << p4.use_count() << '\n';
  std::cout << "p5: " << p5.use_count() << '\n';

  std::cout << "p4: " << p4 << '\n';
  std::cout << "&p4: " << &p4 << '\n';
  std::cout << "p4: " << *p4 << '\n';
  *p4 = 299;
  std::cout << "*intPtr: " << *intPtr << '\n';
  *intPtr = 165;
  std::cout << "p4: " << *p4 << '\n';

  return 0;
}