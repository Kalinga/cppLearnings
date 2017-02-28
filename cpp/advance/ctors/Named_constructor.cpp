    class Fred {
    public:
      // The create() methods are the "named constructors":
      static Fred* create()                 { return new Fred();     }
      static Fred* create(int i)            { return new Fred(i);    }
      static Fred* create(const Fred& fred) { return new Fred(fred); }
      // ...
    private:
      // The constructors themselves are private or protected:
      Fred();
      Fred(int i){};
      Fred(const Fred& fred){};
      // ...
    };

    // Now the only way to create Fred objects is via Fred::create():

    int main()
    {
      Fred* p = Fred::create(5);
      // ...
      delete p;
      // ...
    }