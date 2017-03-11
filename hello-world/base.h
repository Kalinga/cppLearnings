#ifndef BASE_H
#define BASE_H

#include <iostream>

using namespace std;

class Base {
public:
	Base()  {cout << "Base C'tor: this: " <<this<< endl;}
	virtual ~Base() {cout << "Base D'tor: this: " <<this<< endl;}
};

#endif // BASE_H
