    #include <iostream>
    #include <limits>
    int main()
    {
      int age = 0;

      std::cout << "Enter a number: ";

      if (std::cin >> age)
        std::cout << "That's a valid basic_istream \n";
      else
        std::cout << "That's NOT a valid basic_istream \n";

      while ((std::cout << "How old are you? ")
             && !(std::cin >> age)) {
        std::cout << "That's not a number; ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      std::cout << "You are " << age << " years old\n";
      // ...

    }