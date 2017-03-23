#ifndef LOGGER_H
#define LOGGER_H

// logger.h
//#include <stdlib.h>
#include <mutex>
using namespace std;

#define DEBUG_LOG(x) logger::getLogger().write(x)

//forward declaration
class Backend;

class logger{
	enum BackendType {EStream, EFile, EWEBSocket};

public:
	static logger& getLogger();
	void write(string log);

private:
	logger(){};
	~logger(){};
	logger(const logger&){};

	logger& operator =(const logger&  logger){};
	// const logger& operator =(const logger&  logger);
	// operator =(const logger&  logger);
	static logger& createLogger();


private:
	static logger sLogger;
	mutex mMutex;
	Backend* logBackend; //TODO: check if this can be a friend
	BackendType mBackendType;
};

#endif //LOGGER_H