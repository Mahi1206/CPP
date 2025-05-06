/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
2D Point Operations and Undo Mechanism Using Operator Overloading in C++*/
#include <iostream>
using namespace std;

// Point class
class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

struct Node {
    Point data;
    Node* next;
};

class PointStack {
private:
    Node* top;

public:
    PointStack() : top(nullptr) {}

    ~PointStack() {
        while (!isEmpty())
            pop();
    }

    void push(Point p) {
        Node* newNode = new Node{p, top};
        top = newNode;
    }

    Point pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot undo.\n";
            return Point();
        }
        Node* temp = top;
        Point value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Point p1(3, 4), p2(1, 2);
    PointStack operationHistory;

    cout << "Original Points:\n";
    cout << "P1 = "; p1.display(); cout << endl;
    cout << "P2 = "; p2.display(); cout << endl;

    Point p3 = p1 + p2;
    operationHistory.push(p3);
    cout << "\nAfter P1 + P2: "; p3.display(); cout << endl;

    Point p4 = -p3;
    operationHistory.push(p4);
    cout << "After negation: "; p4.display(); cout << endl;

    cout << "\nAre P1 and P2 equal? " << (p1 == p2 ? "Yes" : "No") << endl;

    cout << "\nUndo last operation:\n";
    Point undone = operationHistory.pop();
    cout << "Undone Point: "; undone.display(); cout << endl;

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

