# titbits

* __NULL or 0 or nullptr__


    You should use nullptr as the null pointer value. The others still work for backward
    compatibility with older code. A problem with both NULL and 0 as a null pointer value
    is that 0 is a special “maybe an integer value and maybe a pointer” value
    
* __delete the same pointer twice?__
    
    + That second delete p line might do some really bad things to you.
        + corrupt your heap
        + crash your program
        + make arbitrary and bizarre changes to objects that are already out there on the heap
        + list ongoing....
 * __benefits of using new instead of malloc are:__
 
     + Constructors/destructors: unlike malloc(sizeof(Fred)), new Fred() calls Fred’s constructor.
     + Similarly, delete p calls *p’s destructor.
     + Type safety: malloc() returns a void* which isn’t type safe. 
     + new Fred() returns a pointer of the right type (a Fred*).
     + Overridability: new is an operator that can be overridden by a class, while malloc() is not
       overridable on a per-class basis.
       
* check for null before delete p? __NO__ 
     + __Wrong:__ `if (p != nullptr)   // or just "if (p)" delete p;`
     + __Right:__ `delete p;`
     

        The C++ language guarantees that delete p will do nothing if p is null.
        
* __exception in Fred's ctor, p = new Fred(),“leak” !?__ __NO__


    If an exception occurs during the Fred constructor of p = new Fred(), the C++ language guarantees
    that the memory sizeof(Fred) bytes that were allocated will automagically be released back to the heap.
    
    
        
        

            
