/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Polymorphic Area Calculation System for Geometric Shapes in C++*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class Shape
class Shape {
public:
    virtual float Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};
class Rectangle : public Shape {
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float Area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle Area: " << Area() << endl;
    }
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) : radius(r) {}

    float Area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle Area: " << Area() << endl;
    }
};

int main() {
    cout << "=== Using Dynamic Collection (vector) ===" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(5, 3));
    shapes.push_back(new Circle(4));
    for (Shape* shape : shapes) {
        shape->display();
    }

    // Free memory
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();

    cout << "\n=== Using Static Array ===" << endl;
    Shape* shapeArray[2];
    shapeArray[0] = new Rectangle(2, 6);
    shapeArray[1] = new Circle(2.5);

    for (int i = 0; i < 2; ++i) {
        shapeArray[i]->display();
        delete shapeArray[i];
    }

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

