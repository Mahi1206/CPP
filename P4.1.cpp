/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
   4.1 INHERITANCE-CIRCLES */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Base class representing a generic shape
class Shape {
protected:
    double radius;
public:
    Shape(double r) : radius(r) {}  // Constructor
    virtual double getArea() const = 0; // Pure virtual function
    double getRadius() const { return radius; }
};

// Derived class for circles
class Circle : public Shape {
public:
    Circle(double r) : Shape(r) {}

    // Override the pure virtual function to calculate the area
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

// Class to manage multiple circles dynamically
class CircleManager {
private:
    vector<Circle*> circles; // Using pointers to handle polymorphism
public:
    ~CircleManager() {
        for (Circle* c : circles) {
            delete c; // Free allocated memory
        }
    }

    void addCircle(double radius) {
        circles.push_back(new Circle(radius)); // Dynamically allocate a new circle
    }

    void displayAreas() const {
        for (size_t i = 0; i < circles.size(); ++i) {
            cout << "Circle " << i + 1 << " - Radius: " << circles[i]->getRadius()
                 << ", Area: " << circles[i]->getArea() << endl;
        }
    }
};

int main() {
    CircleManager manager;
    manager.addCircle(2.5);
    manager.addCircle(4.0);
    manager.addCircle(3.2);

    cout << "Circles and their Areas:\n";
    manager.displayAreas();

    cout<<"\n24CE058-Mahima Kukadiya";

    return 0;
}

