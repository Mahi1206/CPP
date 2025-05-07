/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Dynamic Point Manipulation with Method Chaining and Pointer Optimization in C+*/
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point* shift(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")\n";
    }
    static void movePoint(Point* p, int dx, int dy) {
        if (p != nullptr)
            p->shift(dx, dy);
    }
};

int main() {
    // Create point using dynamic memory
    Point* p = new Point(10, 20);

    cout << "Initial: ";
    p->display();

    p->shift(5, -3)->shift(-2, 7)->shift(0, -4);
    cout << "After chaining shifts: ";
    p->display();
    Point::movePoint(p, 10, 10);
    cout << "After static pointer-based move: ";
    p->display();

    delete p;


    cout<<"\n24CE058-Mahima Kukadiya\n";
    return 0;
}

