# “initialization lists” or “assignment”?
* __assignment__
- [x] Temporary Object is being cerated
- [x] Invocation of member object's assignment operator
- [x] member object's default constructor invocation
- [x] memory and resource released (if they are wrong)
- [x] Temporary object destructor

* __initialization lists__


     compiler does not make a separate copy of the object. Even if the types are not the same,
     the compiler is usually able to do a better job with initialization lists than with assignments.
     the result of the `whatever` expression is constructed directly inside member object.
     Conclusion: All other things being equal, your code will run faster if you use
     initialization lists rather than assignment.
     
* For consistency and symmetry, its better to use initialization lists. Below two can't be used in c'tor.
  + non-static const 
  + non-static reference data members
  
  
  
* __But initialization lists can't be used__ 
- [x] initialize the this object’s data members in different orders
- [x] two data members are self-referential
- [x] when a data-member needs a reference to the this object
- [x] you need to do an if…throw test on a variable (parameter, global, etc.) 
      prior to using that variable to initialize one of your this members.

* __initializers be ordered in a constructor’s initialization list__


    Immediate base classes (left to right), then member objects (top to bottom).
    base class sub-objects are initialized first (look up the order if you have
    multiple and/or virtual inheritance!), then data members defined in the class
    are initialized in the order in which they appear in the class declaration)
    
* __initializers list  be used for copy constructor as well__
    
* __order dependency__    
    
    
    the order of member objects in the class body is critical;
    the order of initializers in the constructor initialization list is irrelevant.
    
    