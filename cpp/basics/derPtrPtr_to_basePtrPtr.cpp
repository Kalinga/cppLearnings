    class Vehicle {
    public:
      virtual ~Vehicle() { }
      virtual void startEngine() = 0;
    };
    class Car : public Vehicle {
    public:
      virtual void startEngine();
      virtual void openGasCap();
    };
    class NuclearSubmarine : public Vehicle {
    public:
      virtual void startEngine();
      virtual void fireNuclearMissile();
    };
    int main()
    {
      Car   car;
      Car*  carPtr = &car;
      Car** carPtrPtr = &carPtr;
      Vehicle** vehiclePtrPtr = carPtrPtr;  // This is an error in C++
      NuclearSubmarine  sub;
      NuclearSubmarine* subPtr = &sub;
      *vehiclePtrPtr = subPtr;
      // This last line would have caused carPtr to point to sub !
      carPtr->openGasCap();  // This might call fireNuclearMissile()!
      // ...
    }