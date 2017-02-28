#### There are many uses of placement new.
 
    The simplest use is to place an object at a particular location in memory.
    This is done by supplying the place as a pointer parameter to the new part
    of a new expression:
    
    
------------------------------------------------------------------


    #include <new>        // Must #include this to use "placement new"
    #include "Fred.h"     // Declaration of class Fred
    void someCode()
    {
      char memory[sizeof(Fred)];     // Line #1
      void* place = memory;          // Line #2
      Fred* f = new(place) Fred();   // Line #3 (see "DANGER" below)
      // The pointers f and place will be equal
      // ...
    }
    
    
* Don’t use this “placement new” syntax unless you have to
* Use it only when you really care that an object is placed at a particular location in memory
* For example, when your hardware has a memory-mapped I/O timer device,
  and you want to place a Clock object at that memory location.
* explicitly calling the destructor is needed to clean up
* the only time you ever explicitly call a destructor.  
      
    
    You are taking sole responsibility that the pointer you pass to the “placement new” operator points
    to a region of memory that is big enough and is properly aligned for the object type that you’re creating.
    You are also solely responsible for destructing the placed object.
    This is done by explicitly calling the destructor:
    
-------------------------------------------------------------------    

    // ...the code above
    f->~Fred();   // Explicitly call the destructor for the placed object
