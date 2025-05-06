//THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
//Function Overloading-Based Arithmetic Calculator in C++
#include <iostream>
using namespace std;

// Calculator class with overloaded add functions
class Calculator {
public:
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Add two floats
    float add(float a, float b) {
        return a + b;
    }

    // Add an integer and a float
    float add(int a, float b) {
        return a + b;
    }

    // Add a float and an integer
    float add(float a, int b) {
        return a + b;
    }

    // Display result
    void displayResult(float result) {
        cout << "Result: " << result << endl;
    }
};

int main() {
    Calculator calc;

    // Test cases
    int result1 = calc.add(10, 20);
    float result2 = calc.add(5.5f, 4.5f);
    float result3 = calc.add(10, 3.5f);
    float result4 = calc.add(2.5f, 5);

    // Displaying results
    cout << "Testing Overloaded Add Functions:" << endl;
    calc.displayResult(result1);
    calc.displayResult(result2);
    calc.displayResult(result3);
    calc.displayResult(result4);

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}
