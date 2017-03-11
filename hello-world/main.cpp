#include <iostream>

#include "helloworld.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout<< " Enters main()"<<endl;

	Helloworld hello;
	cout<< hello.speak(" World!")<<endl;

	return 0;
}