#include "helloworld.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Helloworld hello;
	cout<< hello.speak(" World!")<<endl;

	return 0;
}