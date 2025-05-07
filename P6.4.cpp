/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Preventing Memory Leaks with Virtual Destructors in Inheritance (C++ Manual Memory Management)*/
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor called.\n"; }
    virtual ~Base() {
        cout << "Base destructor called.\n";
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[5];
        cout << "Derived constructor: Memory allocated.\n";
    }

    ~Derived() {
        delete[] data;
        cout << "Derived destructor: Memory deallocated.\n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}
