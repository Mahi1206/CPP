/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
   4.2 INHERITANCE-MANAGING MANAGER INFO */
#include <iostream>
using namespace std;
class Person
{
protected:
    string name;
    int age;
public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    void displayPersonInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Employee : public Person
{
protected:
    int empID;
public:
    Employee(int id, string n, int a) : Person(n, a)
    {
        empID = id;
    }
    void displayEmployeeInfo()
    {
        displayPersonInfo();
        cout << "Employee ID: " << empID << endl;
    }
    int getID()
    {
        return empID;
    }
};
class Manager : public Employee
{
protected:
    string department;
public:
    Manager(string dept, int id, int a, string n) : Employee(id, n, a)
    {
        department = dept;
    }
    void displayManagerInfo()
    {
        cout << "Department: " << department << endl;
        displayEmployeeInfo();
    }
};
int main()
{
    int t;
    cout << "Enter the number of managers: ";
    cin >> t;
    Manager** m = new Manager*[t];
    for (int i = 0; i < t; i++)
    {
        string name, dept;
        int id, age;
        cout << "\nManager " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter department: ";
        cin >> ws;
        getline(cin, dept);
        m[i] = new Manager(dept, id, age, name);
    }
    cout << "\nDISPLAYING MANAGER DETAILS " << endl;
    for (int i = 0; i < t; i++)
    {
        cout << "\nManager " << i + 1 << ":\n";
        m[i]->displayManagerInfo();
        delete m[i];
    }
    delete[] m;

    cout<<"\n24CE058-Mahima Kukadiya";

    return 0;
}
