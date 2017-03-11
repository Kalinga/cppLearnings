#include <iostream>

#include "derive.h"

using namespace std;

static Derive staticDerive;

int main(int argc, char const *argv[])
{
	cout<< " Enters main()"<<endl;

	Base *bptr = new Derive(); // Base ptr can hold Derive obj but not vice-versa!!
	delete bptr; // Will call 'only' Base D'tor: if ~Base() is not declared as virtual.
				 // However it will call Derive D'tor: Base D'tor: in-order if ~Base is virtual.
				 // Note: Making ~Derive as virtual will not solve the above problem

	return 0;
}