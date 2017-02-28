    #include <new>       // To get std::set_new_handler
    #include <cstdlib>   // To get abort()
    #include <iostream>  // To get std::cerr

    class alloc_error : public std::exception {
    public:
      alloc_error() : exception() { }
    };

    void myNewHandler()
    {
      // This is your own handler.  It can do anything you want.
      throw alloc_error();

      // Note: If your compiler doesn’t support exception handling,
      // you can, as a last resort, change the line throw …; to:
      // std::cerr << "Attempt to allocate memory failed!" << std::endl;
      // abort();
    }

    int main()
    {
      std::set_new_handler(myNewHandler);   // Install your "new handler"
      // ...
    }