/*THIS PROGRAM IS PREPARED BY 24CE058-Mahima
2.2 Student Record Management*/
#include <iostream>
using namespace std;
class Student
{
    int rollno;
    string name;
    int marks[3];
public:
    // Default constructor
    Student()
    {
        rollno = 0;
        name = "Unknown";
        marks[0] = marks[1] = marks[2] = 0;
    }
    // Parameterized constructor
    Student(int r, string n, int m1, int m2, int m3)
    {
        rollno = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    void setData(int r, string n, int m1, int m2, int m3)
    {
        rollno = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    double calculateAverage()
    {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
    void displayDetails()
    {
        cout << "Roll Number: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
        cout << "    " << endl;
    }
};
int main()
{
    Student students[5];
    // Initializing students with both default and parameterized values
    students[0] = Student(1, "Ram", 85, 90, 78);
    students[1] = Student(2, "Radha", 76, 88, 95);
    students[2] = Student(3, "Krishna", 89, 79, 92);
    students[3] = Student(4, "Sita", 67, 72, 80);
    students[4] = Student(); // Default constructor
    cout << "Student Records:" << endl;
    for (int i = 0; i < 5; i++)
    {
        students[i].displayDetails();
    }
    cout<<"Mahima Kukadiya - 24CE058";
    return 0;
}
