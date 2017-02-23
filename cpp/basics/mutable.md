The point of a mutable class member is that its state does not affect the externally-visible state of a class.
* Synchronisation


    synchronization objects (mutexes, semaphores, atomic spinlocks, etc) -- this is the most common
    case `mutable std::mutex whatever;`. If a const-qualified member function has to acquire a mutex,
    the state of the mutex is changed, so it must be mutable.
    
* Access Counters

    
    access counters, timing, loggers, and other instrumentation that needs to change some state when a
    const-qualified accessor is called
    
* Cache
    
     
    first call to the (const-qualified) accessor calculates the value and stores it in a mutable member
    hash table, second and subsequent calls fetch the value from the table instead.
    
* const_cast
    
    
    const_cast is dangerous and nearly never needed. The biggest use-case is for passing the object to
    an interface where the object is not declared as const (and can’t be changed). In that case you are responsible