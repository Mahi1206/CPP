/* THIS PROGRAM IS PREPARED BY 24CE058-MAHIMA
   3.3 MANAGING BANK ACCOUNTS */
#include <iostream>
using namespace std;
class accounts
{
    int accno;
    string name;
    int balance;
public:
    accounts(int a, string n, int b)
    {
        accno = a;
        name = n;
        balance = b;
    }
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited " << amount << " to account " << accno
                 << ". New balance: " << balance << "\n";
        }
        else
        {
            cout << "Invalid deposit amount.\n";
        }
    }
    void withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accno
                 << ". New balance: " << balance << "\n";
        }
        else
        {
            cout << "Insufficient funds.\n";
        }
    }
    void transfer(accounts* target, int amount)
    {
        if (!target)
        {
            cout << "Target account does not exist.\n";
            return;
        }
        if (amount <= 0)
        {
            cout << "Invalid transfer amount.\n";
            return;
        }
        if (amount > balance)
        {
            cout << "Transfer failed: Insufficient funds.\n";
            return;
        }
        withdraw(amount);
        target->deposit(amount);
        cout << "Transferred " << amount << " from account " << accno
             << " to account " << target->accno << "\n";
    }
    void display() const
    {
        cout << "ACCOUNT NUMBER: " << accno << endl << "NAME: " << name
             <<endl<< "BALANCE: " << balance << "\n";
    }
    int getAccountNumber() const
    {
        return accno;
    }
};
accounts* findaccount(accounts** a, int totalaccounts, int accno)
{
    for (int i = 0; i < totalaccounts; ++i)
    {
        if (a[i]->getAccountNumber() == accno)
        {
            return a[i];
        }
    }
    return nullptr;
}
int main()
{
    accounts* a[100];
    int totalaccounts = 0;
    int choice;
    // Menu-driven system to input accounts and operations
    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Display Account Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            // Create new account
            int accno;
            string name;
            int balance;
            cout << "Enter Account Number: ";
            cin >> accno;
            cin.ignore(); // To clear the newline character
            cout << "Enter Account Holder's Name: ";
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> balance;
            a[totalaccounts++] = new accounts(accno, name, balance);
            cout << "Account created successfully!\n";
            break;
        }
        case 2:
        {
            // Deposit
            int accno, amount;
            cout << "Enter Account Number to Deposit: ";
            cin >> accno;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            accounts* acc = findaccount(a, totalaccounts, accno);
            if (acc)
            {
                acc->deposit(amount);
            }
            else
            {
                cout << "Account not found!\n";
            }
            break;
        }
        case 3:
        {
            // Withdraw
            int accno, amount;
            cout << "Enter Account Number to Withdraw from: ";
            cin >> accno;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            accounts* acc = findaccount(a, totalaccounts, accno);
            if (acc)
            {
                acc->withdraw(amount);
            }
            else
            {
                cout << "Account not found!\n";
            }
            break;
        }
        case 4:
        {
            // Transfer
            int sourceAccno, targetAccno, amount;
            cout << "Enter Source Account Number: ";
            cin >> sourceAccno;
            cout << "Enter Target Account Number: ";
            cin >> targetAccno;
            cout << "Enter Amount to Transfer: ";
            cin >> amount;
            accounts* sourceAcc = findaccount(a, totalaccounts, sourceAccno);
            accounts* targetAcc = findaccount(a, totalaccounts, targetAccno);
            if (sourceAcc && targetAcc)
            {
                sourceAcc->transfer(targetAcc, amount);
            }
            else
            {
                cout << "One or both accounts not found!\n";
            }
            break;
        }
        case 5:
        {
            // Display Account Info
            int x;
            cout << "Enter Account Number to Display Info: ";
            cin >> x;
            accounts* acc = findaccount(a, totalaccounts, x);
            if (acc)
            {
                cout<<"DISPLAYING DETAILS FOR ACCOUNT NUMBER "<< x <<":"<<endl;
                acc->display();
            }
            else
            {
                cout << "Account not found!\n";
            }
            break;
        }
        case 6:
            // Exit
            cout << "Exiting...THANKYOU\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    }
    while (choice != 6);
    for (int i = 0; i < totalaccounts; ++i)
    {
        delete a[i];
    }
    cout<<endl<<"Mahima Kukadiya-24CE058";
}
