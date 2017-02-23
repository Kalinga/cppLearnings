#Reentrancy and Thread-Safety

Throughout the documentation, the terms reentrant and thread-safe are used to mark classes and functions to indicate how they can be used in multithread applications:

    A thread-safe function can be called simultaneously from multiple threads, even when the invocations use shared data, because all references to the shared data are serialized.
    A reentrant function can also be called simultaneously from multiple threads, but only if each invocation uses its own data.

Hence, a thread-safe function is always reentrant, but a reentrant function is not always thread-safe.

By extension, a class is said to be reentrant if its member functions can be called safely from multiple threads, as long as each thread uses a different instance of the class. The class is thread-safe if its member functions can be called safely from multiple threads, even if all the threads use the same instance of the class.

Note: Qt classes are only documented as thread-safe if they are intended to be used by multiple threads. If a function is not marked as thread-safe or reentrant, it should not be used from different threads. If a class is not marked as thread-safe or reentrant then a specific instance of that class should not be accessed from different threads.
Reentrancy

C++ classes are often reentrant, simply because they only access their own member data. Any thread can call a member function on an instance of a reentrant class, as long as no other thread can call a member function on the same instance of the class at the same time. For example, the Counter class below is reentrant:

class Counter
{
public:
    Counter() { n = 0; }

    void increment() { ++n; }
    void decrement() { --n; }
    int value() const { return n; }

private:
    int n;
};

The class isn't thread-safe, because if multiple threads try to modify the data member n, the result is undefined. This is because the ++ and -- operators aren't always atomic. Indeed, they usually expand to three machine instructions:

    Load the variable's value in a register.
    Increment or decrement the register's value.
    Store the register's value back into main memory.

If thread A and thread B load the variable's old value simultaneously, increment their register, and store it back, they end up overwriting each other, and the variable is incremented only once!
Thread-Safety

Clearly, the access must be serialized: Thread A must perform steps 1, 2, 3 without interruption (atomically) before thread B can perform the same steps; or vice versa. An easy way to make the class thread-safe is to protect all access to the data members with a QMutex:

class Counter
{
public:
    Counter() { n = 0; }

    void increment() { QMutexLocker locker(&mutex); ++n; }
    void decrement() { QMutexLocker locker(&mutex); --n; }
    int value() const { QMutexLocker locker(&mutex); return n; }

private:
    mutable QMutex mutex;
    int n;
};

The QMutexLocker class automatically locks the mutex in its constructor and unlocks it when the destructor is invoked, at the end of the function. Locking the mutex ensures that access from different threads will be serialized. The mutex data member is declared with the mutable qualifier because we need to lock and unlock the mutex in value(), which is a const function.
Notes on Qt Classes

Many Qt classes are reentrant, but they are not made thread-safe, because making them thread-safe would incur the extra overhead of repeatedly locking and unlocking a QMutex. For example, QString is reentrant but not thread-safe. You can safely access different instances of QString from multiple threads simultaneously, but you can't safely access the same instance of QString from multiple threads simultaneously (unless you protect the accesses yourself with a QMutex).

Some Qt classes and functions are thread-safe. These are mainly the thread-related classes (e.g. QMutex) and fundamental functions (e.g. QCoreApplication::postEvent()).

* Note: Terminology in the multithreading domain isn't entirely standardized. POSIX uses definitions of reentrant and thread-safe that are somewhat different for its C APIs. When using other object-oriented C++ class libraries with Qt, be sure the definitions are understood.