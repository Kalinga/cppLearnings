#ifndef DERIVE_H
#define DERIVE_H

#include "base.h"

class Derive: public Base
{
public:
	Derive() {cout << "Derive C'tor: this: " <<this<< endl;};
	~Derive() {cout << "Derive D'tor: this: " <<this<< endl;};
	
};

#endif //DERIVE_H