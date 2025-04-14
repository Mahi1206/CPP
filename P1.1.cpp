/*THIS PROGRAM IS PREPARED BY 24CE058-Mahima
1.1 Bank Management System*/
#include <iostream>
using namespace std;
class bankaccount
{
    string name;
    int accno;
    float balance;
public:
    void oppenacc()
    {
        cout<<"Enter Account Holder's Name: ";
        cin>>name;
        cout<<"Enter Account Number: ";
        cin>>accno;
        cout<<"Enter Balance: ";
        cin>>balance;
    }
    void displaydetails()
    {
        cout<<"The Account Details Are as Follows:"<<endl;
        cout<<"NAME:"<<name<<endl;
        cout<<"ACCOUNT NUMBER:"<<accno<<endl;
        cout<<"BALANCE:"<<balance<<endl;
    }
    int deposit()
    {
        int s;
        cout<<"Enter the Amount you want to Deposit: ";
        cin>>s;
        balance=balance+s;
        return balance;
    }
    int withdraw()
    {
        int a;
        cout<<"Enter the Amount you want to Withdraw: ";
        cin>>a;
        if (balance>=a)
        {
            balance=balance-a;
            return balance;
        }
        else
        {
            cout<<"ERROR:Insufficient Balance"<<endl;
        }
    }
    int displaybalance()
    {
        cout<<"The Updated Balance Is:"<<balance<<endl;
    }
};
int main()
{
    bankaccount x;
    int y;
    x.oppenacc();
    x.displaydetails();
    cout<<endl<<"TO DEPOSIT enter 1"<<endl<<"TO WITHDRAW enter 2"<<endl<<"TO CHECK CURRENT BALANCE enter 3"<<endl<<"TO EXIT enter 4"<<endl;

    do{
        cout<<"Enter Your Choice:";
        cin>>y;
        switch(y)
        {
        case 1:
            x.deposit();
            break;
        case 2:
            x.withdraw();
            break;
        case 3:
            x.displaybalance();
            break;
        case 4:
            cout<<"Thank you!"<<endl;
            break;
        default:
            cout<<"Please Enter Valid Choice!"<<endl;
        }
    }
    while(y!=4);
    cout<<endl<<"Mahima Kukadiya - 24CE058";

}

