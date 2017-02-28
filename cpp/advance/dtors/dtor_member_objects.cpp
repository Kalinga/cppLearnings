#include <iostream>
#include <string>
using namespace std;

    class Member {
    public:
      Member()  {cout<< this<<endl;}
      ~Member() {cout<< this<<endl;}
      // ...
    private:
    };

    class Fred {
    public:
      ~Fred();
      // ...
    private:
      //string x_name = string("x");
      //Member x_(x_name );         // warning: non-static data member initializers only available with -std=c++11

      Member x_;
      Member y_;
      Member z_;
    };

    Fred::~Fred()
    {
      // Compiler automagically calls z_.~Member()
      // Compiler automagically calls y_.~Member()
      // Compiler automagically calls x_.~Member()
    }

    int main(int argc, char ** argv)
    {
        Fred myFred;
        cout<<"======Ctor Done!======"<<endl;
        return 0;
    }

#if 0
//A Sample output
0x7fff0f3b10d0
0x7fff0f3b10d1
0x7fff0f3b10d2
======Ctor Done!======
0x7fff0f3b10d2
0x7fff0f3b10d1
0x7fff0f3b10d0
#endif
