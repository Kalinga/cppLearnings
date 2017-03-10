#include "helloworld.h"
using namespace std;

// This is a Hello world class.
Helloworld::Helloworld() {

}

Helloworld::~Helloworld() {

}


string Helloworld::speak(string sub) {
	return string("Hello") + sub;
}
