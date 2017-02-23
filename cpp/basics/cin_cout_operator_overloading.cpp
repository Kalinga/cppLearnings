    #include <iostream>

    class Fred {
    public:
      Fred(int i = 0);
      friend std::ostream& operator<< (std::ostream& o, const Fred& fred);
      friend std::istream& operator>> (std::istream& i, Fred& fred);
      // ...
    private:
      int i_;    // Just for illustration
    };

    Fred::Fred(int i):i_(i) {}

    std::ostream& operator<< (std::ostream& o, const Fred& fred)
    {
      return o << fred.i_;
    }

    std::istream& operator>> (std::istream& i, Fred& fred)
    {
      return i >> fred.i_;
    }

    int main()
    {
      Fred f;
      std::cout << "My Fred object: " << f << "\n";
      std::cout << "Enter a a number for Fred object's i: ";
      std::cin>>f;
      std::cout << "My Fred object: " << f << "\n";
      // ...
    }

