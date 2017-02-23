#Signals and slots

are used for communication between objects. The signals and slots mechanism is a central feature of Qt
Signals and slots are made possible by Qt's meta-object system. A slot is a function that is called in
response to a particular signal.

    A signal can be connected to many slots and signals. Many signals can be connected to one slot.

If a signal is connected to several slots, the slots are activated __in the same order in which the connections were made__,
when the signal is emitted. By default, a signal is emitted for every connection you make;
two signals are emitted for duplicate connections. f you pass the Qt::UniqueConnection type,
the connection will only be made if it is not a duplicate.


* Type Safe


    Signals and slots can take any number of arguments of any type. They are completely type safe.
    he signature of a signal must match the signature of the receiving slot. (In fact a slot may 
    have a shorter signature than the signal it receives

* Loose Couping


    Signals and slots are loosely coupled: A class which emits a signal neither knows nor
    cares which slots receive the signal.
    This is true information encapsulation, and ensures that the object can be used as a software component.

* Alternative:


     Other successful frameworks using this method do exist, callbacks can be unintuitive and may suffer
     from problems in ensuring the type-correctness of callback arguments.
     
* Component Programming:
     
     
     a slot does not know if it has any signals connected to it. Signal does not know or care whether anything
     is receiving the signals it emits. It is even possible to connect a signal directly to another signal.
     Together, signals and slots make up a powerful component programming mechanism.
     
     