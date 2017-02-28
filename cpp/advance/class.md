# Class 

    The fundamental building block of OO software.
    A class defines a data type, much like a struct would be in C.
    In a computer science sense, a type consists of both a set of states
    and a set of operations which transition between those states.
    
# Object
   
    A region of storage with associated semantics.
    “object” usually means “an instance of a class.”
    Thus a class defines the behavior of possibly many objects (instances).
    
# Encapsulation
    
    Preventing unauthorized access to some piece of information or functionality.
    
# Encapsulation
    
    Preventing unauthorized access to some piece of information or functionality.
    encapsulating (putting “in a capsule”) the implementation forces users to use the interface.
    
- For a single class, the volatile part is normally encapsulated using the private and/or protected keywords.
- For a tight group of classes, encapsulation can be used to deny access to entire classes in that group.
Inheritance can also be used as a form of encapsulation.
- single class, the interface is simply the class’s public member functions and friend functions
- tight group of classes, the interface can include several of the classes in the chunk.
    
# Layout of C++ objects in Memory
    
 - C++ doesn’t define layouts
 - just semantic constraints that must be met.
 - Basically, C++ constructs objects simply by concatenating sub objects. 
 - Virtual functions are typically implemented by adding a pointer
   (the “vptr”) to each object of a class with virtual functions.
 - Each class has its own vtbl shared by all objects of that class.
 
# one constructor of a class call another constructor of the same class

    Nope. do NOT try to achieve this via placement new.
    new(this) Foo(x, int(x)+7) within the body of Foo::Foo(char) might look very tempting.
    However that is bad, bad, bad. it’s bad. Constructors do a bunch of little magical
    things behind the scenes, but that bad technique steps on those partially constructed
    bits. Just say no.

    