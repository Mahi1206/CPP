/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Temperature Conversion System with Operator Overloading and FIFO Management in C++*/
#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;
class Celsius {
    float temp;
public:
    Celsius(float t = 0) : temp(t) {}

    float getTemp() const { return temp; }
    operator Fahrenheit();
    bool operator==(const Fahrenheit& f);
};

class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t = 0) : temp(t) {}

    float getTemp() const { return temp; }

    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }
    bool operator==(const Celsius& c) {
        return (temp == (c.getTemp() * 9 / 5) + 32);
    }
};
Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}
bool Celsius::operator==(const Fahrenheit& f) {
    return ((temp * 9 / 5) + 32) == f.getTemp();
}

int main() {
    Celsius c1(0), c2(100);
    Fahrenheit f1(32), f2(212);

    Fahrenheit f_from_c1 = c1;
    Celsius c_from_f2 = f2;

    cout << "Celsius " << c1.getTemp() << "C = " << f_from_c1.getTemp() << "F\n";
    cout << "Fahrenheit " << f2.getTemp() << "F = " << c_from_f2.getTemp() << "C\n";

    cout << "Are 0C and 32F equal? " << (c1 == f1 ? "Yes" : "No") << endl;
    cout << "Are 100C and 212F equal? " << (c2 == f2 ? "Yes" : "No") << endl;

    queue<Fahrenheit> tempQueue;
    tempQueue.push(c1);
    tempQueue.push(c2);

    cout << "\nQueue (FIFO) of Fahrenheit conversions from Celsius:\n";
    while (!tempQueue.empty()) {
        cout << tempQueue.front().getTemp() << "F\n";
        tempQueue.pop();
    }
    Fahrenheit tempArray[2] = { c1, c2 };

    cout << "\nArray of Fahrenheit conversions from Celsius:\n";
    for (int i = 0; i < 2; ++i) {
        cout << tempArray[i].getTemp() << "F\n";
    }

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

