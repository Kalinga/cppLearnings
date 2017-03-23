#ifndef BACKEND_H
#define BACKEND_H

#include <iostream>

class Backend{
public:
	virtual void write(string log) = 0;
private:
	Backend(){};
	~Backend(){};
	Backend(const Backend&){};

	Backend& operator =(const Backend&  backend){};

private:

};

class StreamBackend: public Backend
{
public:
	void write(string log);
	
};

void StreamBackend::write(string log)
{
	std::cout<<log<<endl;
}
#endif //BACKEND_H