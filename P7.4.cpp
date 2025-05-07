/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Student Performance Report Generator Using File I/O and Custom Formatting in C++*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

ostream& tabular(ostream& out) {
    out << left << setw(15);
    return out;
}

int main() {
    ifstream fin("students.txt");

    if (!fin) {
        cout << "Error: Could not open file 'students.txt'\n";
        return 1;
    }

    char name[50];
    int marks;
    char grade;

    cout << tabular << "Name" << tabular << "Marks" << tabular << "Grade" << endl;
    cout << string(40, '-') << endl;
    while (fin >> name >> marks >> grade) {
        cout << tabular << name << tabular << marks << tabular << grade << endl;
    }

    fin.close();

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

