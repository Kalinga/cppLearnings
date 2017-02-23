#include <iostream>

    class Base {
    public:
      friend std::ostream& operator<< (std::ostream& o, const Base& b);
      // ...
    protected:
      virtual void printOn(std::ostream& o) const = 0;  // Or plain virtual; see below
    };

    inline std::ostream& operator<< (std::ostream& o, const Base& b)
    {
      std::cout << "friend std::ostream& operator: " << "\n";
      b.printOn(o);
      return o;
    }

    class Derived : public Base {
    public:
      // ...
    protected:
      virtual void printOn(std::ostream& o) const;
    };

    void Derived::printOn(std::ostream& o) const
    {
      std::cout << "Derived::printOn: "  << "\n";
    }


    int main()
    {
      Derived d;
      std::cout << "Printing My Derived object: \n" << d << "\n";
    }

