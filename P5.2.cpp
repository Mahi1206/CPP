/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Complex Number Operations Using Operator Overloading in C++*/
#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    vector<Complex> complexList = {c1, c2, sum, diff};
    cout << "\nAll Complex Numbers in Collection:\n";
    for (size_t i = 0; i < complexList.size(); ++i) {
        cout << "Complex[" << i << "]: " << complexList[i] << endl;
    }

    cout<<"24CE058-Mahima Kukadiya";

    return 0;
}

