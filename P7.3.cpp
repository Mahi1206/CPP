/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Basic File-Based Inventory Management System in C++*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(const char* filename) {
    Product p;
    cout << "Enter product name: ";
    cin.getline(p.name, 50);
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;
    cin.ignore();

    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cout << "Error opening file for writing.\n";
        return;
    }

    fout.write((char*)&p, sizeof(p));
    fout.close();
    cout << "Product added successfully.\n";
}

void viewInventory(const char* filename) {
    Product p;
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Error opening file for reading.\n";
        return;
    }

    cout << "\n--- Inventory ---\n";
    while (fin.read((char*)&p, sizeof(p))) {
        cout << "Name: " << p.name << ", Quantity: " << p.quantity << ", Price: $" << p.price << endl;
    }
    fin.close();
}

void searchProduct(const char* filename) {
    char searchName[50];
    cout << "Enter product name to search: ";
    cin.getline(searchName, 50);

    Product p;
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "Error opening file for reading.\n";
        return;
    }

    bool found = false;
    while (fin.read((char*)&p, sizeof(p))) {
        if (strcmp(p.name, searchName) == 0) {
            cout << "Product found:\n";
            cout << "Name: " << p.name << ", Quantity: " << p.quantity << ", Price: $" << p.price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }

    fin.close();
}

int main() {
    const char* filename = "inventory.dat";
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addProduct(filename); break;
            case 2: viewInventory(filename); break;
            case 3: searchProduct(filename); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

