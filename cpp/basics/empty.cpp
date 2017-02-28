#include <iostream>
using namespace std;

    class Empty { };
    void f()
    {
        Empty a, b;
        if (&a == &b) cout << "impossible: report error to compiler supplier";
        Empty* p1 = new Empty;
        Empty* p2 = new Empty;
        if (p1 == p2) cout << "impossible: report error to compiler supplier";
        else cout << "All is well! \n";
    }

    struct X : Empty {
        int a;
        // ...
    };

    void g(X* p)
    {
        void* p1 = p;
        void* p2 = &p->a;
        if (p1 == p2) cout << "nice: good optimizer \n";
    }

    int main()
    {
        f();
        X x;
        g(&x);
    }