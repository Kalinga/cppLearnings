# Mutex vs Semaphore

* mutex and semaphore are kernel resources
* they provide synchronization services
* They are also called as synchronization primitives

# Atomicity
* unbreakability
* uninterrupted operation

`count++;` // count has permanent storage in RAM is a statement

The above statement can be decomposed into, at least three operations.(atomic instruction)
 -   Fetching count value
 -   Incrementing count value
 -   Storing the updated value
 
`instructions are atomic but statements a composed of several instructions, so NOT atomic`
 
# Using Mutex:
 * A mutex provides mutual exclusion
 * either producer or consumer can have the key (mutex)
 * Once have the key, proceed with their work
 * As long as the resource is used by producer, the consumer needs to wait
 * vice versa
 * At any point of time, only one thread can work with the entire resource
 * Strictly speaking, a mutex is locking mechanism used to synchronize access to a resource
 * Only one task (can be a thread or process based on OS abstraction) can acquire the mutex
 * It means there is ownership associated with mutex, and only the owner can release the lock (mutex)
 
# Using Semaphore:

* A semaphore is a generalized mutex
* A semaphore can be associated with splitted resource/several resources
* The consumer and producer can work on different resource at the same time
* Semaphore is signaling mechanism (“I am done, you can carry on” kind of signal)

# mutex, semaphore, event, critical section, etc…
 
 * All are same
 * All are synchronization primitives
 * Based on their cost in using them they are different
 * We should consult the OS documentation for exact details
 
# Priority Inversion :
 * it’s a problem which arises sometimes when Priority based scheduling is used by OS
 * For three tasks priorities are in the order of L < M < H
 * L or H don't share CS with M
 * L running in CS, And H waiting to run in same CS
 * M arrives and preempts CS, as they have no CS dependency
 * M finishes and L starts, as L should unlock the lock it might have put around CS
 * H is still waiting for the resource -> priority Inversion
 * Solution to this problem is priority inheritance
 
# Priority inheritance:


    Temporarily changing priority of a lower priority task to the priority of a high priority task;
    that is waiting for the lower priority task to finish the CS. 
 
