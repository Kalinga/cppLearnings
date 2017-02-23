# POD


    A POD type is a C++ type that has an equivalent in C, and that uses the same rules as C uses for initialization,
    copying, layout, and addressing.
    
- [X] static data members,  
- [X] static member functions
- [X] non-static (non-virtual) member functions
- [ ] base classes
- [ ] virtual functions
- [ ] assignment operator 
- [ ] constructors 
- [ ] destructors
- [ ] non-static members that are private or protected

* __For Example:__
- [x]  bool
- [x]  any numeric type
- [x]  various char variants
- [x]  any enumeration type
- [x]  any data-pointer type (any type convertible to void*)
- [x]  any pointer-to-function type
- [x]  any POD type
- [x]  arrays of any of these
- [ ]  pointers-to-member
- [ ]  references

* __operator overload that works with built-in / intrinsic / primitive types__


    No, the C++ language requires that your operator overloads take at least one operand
    of a “class type” or enumeration type. The C++ language will not let you define an
    operator all of whose operands / parameters are of primitive types.


