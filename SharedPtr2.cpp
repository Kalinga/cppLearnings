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
  std::cout << std::boolalpha;
  std::tr1::shared_ptr<int> foo(new int (10));

  int *barIntPtr = new int;
  std::cout << "barIntPtr: " << barIntPtr << '\n';
  *barIntPtr = 65;
  //std::cout << "*barIntPtr: " << *barIntPtr << '\n';

  std::tr1::shared_ptr<int> bar (barIntPtr);
  std::tr1::shared_ptr<int> foofoo (foo);
  
  std::cout << "*foo: " << *foo << '\n';
  std::cout << "*bar: " << *bar << '\n';
  
  std::cout << "use_count:\n";
  std::cout << "foo: " << foo.use_count() << '\n';
  std::cout << "bar: " << bar.use_count() << '\n';
  
  std::cout << "foo is unique?" << foo.unique() << '\n';
  std::cout << "bar is unique? " << bar.unique() << '\n';
  
  std::cout << "...................SWAPPED...................." <<'\n';
  foo.swap(bar);

  std::cout << "*foo: " << *foo << '\n';
  std::cout << "*bar: " << *bar << '\n';

  std::cout << "use_count:\n";
  std::cout << "foo: " << foo.use_count() << '\n';
  std::cout << "bar: " << bar.use_count() << '\n';
  
  
  std::cout << "foo is unique?" << foo.unique() << '\n';
  std::cout << "bar is unique? " << bar.unique() << '\n';

  std::cout << "foo.get" << foo.get() << '\n';
  std::cout << "*(foo.get)" << *foo.get() << '\n';
  
  return 0;
}