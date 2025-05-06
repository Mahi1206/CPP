/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
   4.5 INHERITANCE-GRADE DEFINGING SYSTEM  */
#include<iostream>
#include<string>
using namespace std;
class GradingSystem
{
protected:
    string student_name;
    float marks;
public:
    GradingSystem(string name, float m) : student_name(name), marks(m) {}

    virtual void compute_grade() = 0;

    void display_student_info()
    {
        cout << "Student Name: " << student_name << endl;
        cout << "Marks: " << marks << endl;
    }
};

class Undergraduate : public GradingSystem
{
public:
    Undergraduate(string name, float m) : GradingSystem(name, m) {}

    void compute_grade() override
    {
        string grade;
        if (marks >= 90)
        {
            grade = "A+";
        }
        else if (marks >= 80)
        {
            grade = "A";
        }
        else if (marks >= 70)
        {
            grade = "B+";
        }
        else if (marks >= 60)
        {
            grade = "B";
        }
        else if (marks >= 50)
        {
            grade = "C";
        }
        else
        {
            grade = "F";
        }
        cout << "GRADE: " << grade << endl;
    }
};

class Postgraduate : public GradingSystem
{
public:
    Postgraduate(string name, float m) : GradingSystem(name, m) {}

    void compute_grade() override
    {
        string grade;
        if (marks >= 85)
        {
            grade = "A+";
        }
        else if (marks >= 75)
        {
            grade = "A";
        }
        else if (marks >= 65)
        {
            grade = "B+";
        }
        else if (marks >= 55)
        {
            grade = "B";
        }
        else if (marks >= 45)
        {
            grade = "C";
        }
        else
        {
            grade = "F";
        }
        cout << "GRADE: " << grade << endl;
    }
};

int main()
{
    int choice;
    string name;
    float marks;
    int student_type;
    GradingSystem* students[100];
    int student_count = 0;

    do
    {
        cout << "1. Add Undergraduate Student\n"
             << "2. Add Postgraduate Student\n"
             << "3. Display Student Grades\n"
             << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        GradingSystem* student = nullptr;

        switch (choice)
        {
        case 1:
            cout << "Enter Undergraduate student name: ";
            cin >> name;
            cout << "Enter marks for " << name << ": ";
            cin >> marks;
            student = new Undergraduate(name, marks);
            students[student_count++] = student;
            student->display_student_info();
            student->compute_grade();
            break;

        case 2:
            cout << "Enter Postgraduate student name: ";
            cin >> name;
            cout << "Enter marks for " << name << ": ";
            cin >> marks;
            student = new Postgraduate(name, marks);
            students[student_count++] = student;
            student->display_student_info();
            student->compute_grade();
            break;

        case 3:
            if (student_count == 0)
            {
                cout << "No student records available." << endl;
            }
            else
            {
                cout<<endl<<"DISPLAYING STUDENT RECORDS"<<endl;
                for (int i = 0; i < student_count; i++)
                {
                    cout<<"STUDENT "<<i+1<<":"<<endl;
                    students[i]->display_student_info();
                    students[i]->compute_grade();
                }
            }
            break;

        case 4:
            cout << "Exiting program." << endl;
            for (int i = 0; i < student_count; i++)
            {
                delete students[i];
            }
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
    while (choice != 4);

    cout<<endl<<"\n24CE058-Mahima Kukadiya\n"<<endl;
}
