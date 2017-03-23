#include "logger.h"
#include "Backend.h"

#include <iostream>
using namespace std;

// logger.cpp
// Ckeck if this causes static initialization-order problem for multiple process 
logger logger::sLogger = logger::createLogger();

logger& logger::createLogger() {
	static logger _logger;
	return _logger;
}

logger& logger::getLogger() 
{
	static bool backend_init = false;
	if (!backend_init) {
	// read config using yajl from logconfig.json
	// backendType = yajl.getConfig()
	// switch: case
	//mBackendType: logBackend = new StreamBackend( )
		//logBackend = new StreamBackend();
		//backend_init = true;
	}

	return sLogger;
}

void logger::write(string log)
{
	mMutex.lock(); // TODO: try_lock
		cout<<log<<endl;
		//logBackend.write(log);
	mMutex.unlock();	
}

// main.cpp
#include "logger.h"

int main(int argc, char** arcv) {
	DEBUG_LOG("inside Main");
	return 0;
}
 #if 0
//logConfig.json
{
	backend:"stream",
	mode:"synchronous"
	port:"1020"
}
#endif