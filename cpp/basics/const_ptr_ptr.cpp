
#if 0

    class Foo { /* ... */ };
    void f(const Foo** p);
    void g(const Foo* const* p);

    int main()
    {
      Foo** p = /*...*/;
      // ...
      f(p);  // ERROR: it's illegal and immoral to convert Foo** to const Foo**
      g(p);  // Okay: it's legal and moral to convert Foo** to const Foo* const*
      // ...
    }
#endif

    class Foo {
    public:
      void modify();  // make some modification to the this object
    };
    int main()
    {
      const Foo x;
      Foo* p;
      const Foo** q = &p;  // q now points to p; this is (fortunately!) an error
      *q = &x;             // p now points to x
      p->modify();         // Ouch: modifies a const Foo!!
      // ...
    }

