
/*THIS PROGRAM IS PREPARED BY 24CE058-Mahima Kukadiya
2.3 BANK MANAGEMENT SYSTEM*/
#include <iostream>
using namespace std;
class bankaccount
{
    string name;
    int accno, balance;
public:
    // Default constructor
    bankaccount()
    {
        name = "n/a";
        accno = 0;
        balance = 0;
    }
    // Parameterized constructor
    bankaccount(string n, int a, int b)
    {
        name = n;
        accno = a;
        balance = b;
    }
    // Deposit function
    void deposit(int amount)
    {
        balance += amount;
    }
    // Withdraw function
    void withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "ERROR: Insufficient Balance" << endl;
        }
    }
    // Display account details
    void displaydetails()
    {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    bankaccount accounts[5];
    // Initializing accounts with correct order
    accounts[0] = bankaccount("Alice", 101, 5000);
    accounts[1] = bankaccount("Bob", 102, 3000);
    accounts[2] = bankaccount("Charlie", 103, 7000);
    accounts[3] = bankaccount("David", 104, 10000);
    accounts[4] = bankaccount(); // Default constructor is automatically called
    cout << "Bank Accounts Summary:" << endl;
    for (int i = 0; i < 5; i++)
    {
        accounts[i].displaydetails();
        cout << "    " << endl;
    }
    char choice;
    do
    {
        int index, operation;
        cout << "Do you want to update any account? (y/n): ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Enter account index (1 to 5): ";
            cin >> index;
            if (index > 0 && index <= 5)
            {
                cout << "Choose operation: 1. Deposit 2. Withdraw: ";
                cin >> operation;
                int amount;
                cout << "Enter amount: ";
                cin >> amount;
                if (operation == 1)
                {
                    accounts[index - 1].deposit(amount);
                }
                else if (operation == 2)
                {
                    accounts[index - 1].withdraw(amount);
                }
                else
                {
                    cout << "Invalid operation!" << endl;
                }
                cout << "Updated Account Details:" << endl;
                accounts[index - 1].displaydetails();
            }
            else
            {
                cout << "Invalid account number!" << endl;
            }
        }
    } while (choice == 'y');

    cout<<endl<<"Mahima Kukadiya - 24CE058";
    return 0;
}
