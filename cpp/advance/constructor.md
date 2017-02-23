# CTors

* __this pointer in the constructor !__


    even if the caller is constructing an object of a derived class, during the constructor of the
    base class, your object is not yet of that derived class. So virtual machanism will not work.
    
    