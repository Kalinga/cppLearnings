##### What’s the order that local objects are destructed?  

`In reverse order of construction: First constructed, last destructed.`

In the following example, **b’s destructor will be executed first**, then a’s destructor:

    void userCode()
    {
      Fred a;
      Fred b;
      // ...
    }
    
##### What’s the order that objects in an array are destructed?  

`In reverse order of construction: First constructed, last destructed.`

In the following example, the order for destructors will be __a[9], a[8], …, a[1], a[0]__:

    void userCode()
    {
      Fred a[10];
      // ...
    }

#### overload the destructor for my class!

* `No`
* You can have only one destructor for a class Fred. It’s always called Fred::~Fred().
* It never takes any parameters, and it never returns anything.
* You can’t pass parameters to the destructor anyway
* you never explicitly call a destructor (well, almost never).


#### destructors for member objects


- A class’s destructor (whether or not you explicitly define one) automagically invokes
  the destructors for member objects.
- They are destroyed in the `reverse order they appear within the declaration for the class`

#### destructor Order
- members
    - reverse order of declaration in the class 
- base classes
    - reverse order of appearance in the inheritance list
- Order dependencies with virtual inheritance are trickier.
    
    
#### throw an exception from a destructor!

    never throw an exception from a destructor

`never throw an exception from a destructor while processing another exception.` 
How ever this is quite difficult to write in destructor. So the rule of thumb is
__`never throw an exception from a destructor`__