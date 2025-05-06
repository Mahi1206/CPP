/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Custom Dynamic Array with Manual Memory Management in C++*/
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < size; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 2) {
        data = new int[initialCapacity];
        capacity = initialCapacity;
        size = 0;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity)
            resize();
        data[size++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            return;
        }

        for (int i = index; i < size - 1; ++i)
            data[i] = data[i + 1];

        size--;
    }

    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicArray arr;

    // Insert elements
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.display();  // 10 20 30 40

    // Remove element at position 1
    arr.removeAt(1);
    arr.display();  // 10 30 40

    // Remove invalid index
    arr.removeAt(10);  // Invalid index!

    cout << "Current size: " << arr.getSize() << endl;
    cout << "Current capacity: " << arr.getCapacity() << endl;

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

