/* THIS PROGRAM IS PREPARED BY 24CE058-Mahima Kukadiya
   3.1 EMPLOYEE SALARY MANAGEMENT */
#include<iostream>
using namespace std;
class employee
{
    string name;
    int salary;
    int bonus;
    int totalsalary;
public:
    employee()//default constructor
    {
        bonus=1500;//default bonus
    }
    employee(string n,int s,int b)//parametarised constructor
    {
        name=n;
        salary=s;
        bonus=b;
        totalsalary=caltotalsalary();
    }
    inline int caltotalsalary()//inline function
    {
        return totalsalary=salary+bonus;
    }
    void display()
    {
        cout<<"Name of Employee: "<<name<<endl;
        cout<<"Salary of Employee: "<<salary<<endl;
        cout<<"Bonus of Employee: "<<bonus<<endl;
        cout<<"Total Salary of Employee: "<<totalsalary<<endl<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter the Number of Employee you want to Add the Datas For:";
    cin>>n;
    employee** e = new employee*[n];
    for(int i=0;i<n;i++)
    {
        string name;
        int bonus,salary;
        string x;
        cout<<"Enter the Name of the Emplyoee "<< i+1 << ":";
        cin>>name;
        cout<<"Enter the Salary of Employee " <<i+1<<":";
        cin>>salary;
        cout<<"Do you wnat to enter extra bonus for this employee? (y/n)";
        cin>>x;
        if(x=="y" || x=="Y")
        {
            cout<<"Enter the bonus ammount you want to add for employee " <<i+1<<":";
            cin>>bonus;
            e[i]= new employee(name,salary,bonus);
        }
        else if (x=="n" || x=="N")
        {
            cout<<"Applying Default Bonus for this Employee"<<endl;
            e[i]=new employee(name,salary,1500);
        }
        else
        {
            cout<<"Please Enter a Valid Choice"<<endl;
        }
       cout<<endl;
    }
    for (int i=0;i<n;i++)
    {
        cout<<"Details Of the Employee "<<i+1<<":"<<endl;
        e[i]->display();
    }
    for (int i = 0; i < n; i++)
    {
        delete e[i];
    }
    cout<<"Mahima Kukadiya - 24CE058";
}
