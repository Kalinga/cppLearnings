#include <iostream>

#include "base.h"

using namespace std;

static Base staticBase;

int main(int argc, char const *argv[])
{
	cout<< " Enters main()"<<endl;

	Base *bptr = new Base(); // Memory Leak
	Base stackObj; // Automatic ~Base() will be called

	Base arr[5]; // Automatic ~Base() will be called for all array elements

	cout<<"===========================Array of Objects on Heap: STRAT====================="<<endl;
	Base *arrPtr = new  Base[5];
	delete[] arrPtr;
	cout<<"=================Array of Objects on Heap: END. AUTO Objects deletetion STRAT=="<<endl;

	return 0;
}