# const correctness

* __The benefit of const correctness is that it prevents you from inadvertently modifying something you didn’t
  expect would be modified.__
   
* __const X* p__


    "p is a pointer to an X that is constant."
    For example, if class X has a const member function such as inspect() const, it is okay to say p->inspect().
    But if class X has a non-const member function called mutate(), it is an error if you say p->mutate().
    No runtime overhead — the compiler does the work at compile-time
    
* __“const X* p”, “X* const p” and “const X* const p”__


    const X* p means “p points to an X that is const”: the X object can’t be changed via p.
    X* const p means “p is a const pointer to an X that is non-const”: you can’t change the pointer p itself, but you can change the X object via p.
    const X* const p means “p is a const pointer to an X that is const”: you can’t change the pointer p itself, nor can you change the X object via p.

* __Styles (const-on-the-right vs const-on-the-left)__
    
    * __`X const& x` is equivalent to `const X& x`__ 
    * __`X const* x` is equivalent to `const X* x`__

* __Nonsense__


    Does “X& const x” :it is nonsense. “x is a const reference to a X”. But that is redundant — 
    references are always const
    
* __const member function return by Reference__    


    a const member function must not change (or allow a caller to change) the this object’s logical state
    So const member function must return by a const Reference.
    const std::string& name_good() const; 
    std::string& name_evil() const;  # This allowes the caller to modify a const object data
    
* __`const int*` promise__


    “const int* p” means “p promises not to change the *p,” not “*p promises not to change.”

* [__pointer-cast__](const_ptr_ptr.cpp)
    + Foo** ->const Foo**: would be invalid and dangerous.
    - Same (invalid and dangerous)with Der** -> Base** However Der*->Base* is OK  
 
 
    please do not pointer-cast your way around that compile-time error message. Just Say No!
    