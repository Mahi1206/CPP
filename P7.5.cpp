/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Structured Student Report with Aligned Output and Currency Formatting in C++*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

ostream& currency(ostream& out) {
    out << "$";
    return out;
}

int main() {
    const int SIZE = 3;
    string names[SIZE] = {"Mahima", "Vishvam", "Dhruvi"};
    int marks[SIZE] = {85, 92, 78};
    float fees[SIZE] = {4500.5, 4700, 4200.75};

    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    for (int i = 0; i < SIZE; ++i) {
        cout << left << setw(15) << names[i]
             << setw(10) << marks[i]
             << currency << fixed << setprecision(2) << fees[i] << endl;
    }

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

