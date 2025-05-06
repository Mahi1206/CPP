/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
   4.4 INHERITANCE-ACCOUNT MANAGEMENT INFO */
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class banking_account
{
protected:
    int acc_num;
    float acc_bal;
    float pre_bal;
public:
    banking_account(int n, float b)
    {
        acc_num = n;
        acc_bal = b;
    }
    virtual void deposit(float amount, const string& transaction_file)
    {
        pre_bal = acc_bal;
        acc_bal += amount;
        ofstream file(transaction_file, ios::app);
        if (file.is_open())
        {
            file << "Deposited: " << amount << " | Balance: " << acc_bal << endl;
            file.close();
        }
        else
        {
            cout << "Error opening transaction file." << endl;
        }
    }
    virtual void withdraw(float amount, const string& transaction_file)
    {
        pre_bal = acc_bal;
        if (acc_bal >= amount)
        {
            acc_bal -= amount;
            ofstream file(transaction_file, ios::app);
            if (file.is_open())
            {
                file << "Withdrawn: " << amount << " | Balance: " << acc_bal << endl;
                file.close();
            }
            else
            {
                cout << "Error opening transaction file." << endl;
            }
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }
    void undo_last_transaction(const string& transaction_file)
    {
        acc_bal = pre_bal;
        ofstream file(transaction_file, ios::app);
        if (file.is_open())
        {
            file << "Transaction undone | Balance: " << acc_bal << endl;
            file.close();
        }
        else
        {
            cout << "Error opening transaction file." << endl;
        }
    }
};

class saving_account : public banking_account
{
    int interest_rate;
public:
    saving_account(int num, float bal, int r) : banking_account(num, bal)
    {
        interest_rate = r;
    }
    void apply_interest(const string& transaction_file)
    {
        float interest = (acc_bal * interest_rate) / 100;
        acc_bal += interest;
        ofstream file(transaction_file, ios::app);
        if (file.is_open())
        {
            file << "Applied interest: " << interest << " | Balance: " << acc_bal << endl;
            file.close();
        }
        else
        {
            cout << "Error opening transaction file." << endl;
        }
    }
};
class current_account : public banking_account
{
    float limit;
public:
    current_account(int num, float bal, float lim) : banking_account(num, bal)
    {
        limit = lim;
    }
    void withdraw(float amount, const string& transaction_file) override
    {
        pre_bal = acc_bal;
        if (acc_bal + limit >= amount)
        {
            acc_bal -= amount;
            ofstream file(transaction_file, ios::app);
            if (file.is_open())
            {
                file << "Withdrawn: " << amount << " | Balance: " << acc_bal << endl;
                file.close();
            }
            else
            {
                cout << "Error opening transaction file." << endl;
            }
        }
        else
        {
            cout << "Exceeds overdraft limit." << endl;
        }
    }
};
void show_transaction_history(const string& transaction_file)
{
    ifstream file(transaction_file);
    string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No transaction history available." << endl;
    }
}
int main()
{
    int choice, acc_counter = 0;
    int number, rate;
    float balance, limit;
    saving_account* s = nullptr;
    current_account* c = nullptr;
    string transaction_file;
    cout<<"MENU-"<<endl;
    cout << "1  Create saving account\n2  Create current account\n"
         << "3  Deposit to saving account\n4  Withdraw from saving account\n"
         << "5  Deposit to current account\n6  Withdraw from current account\n"
         << "7  See transaction history\n8  Undo last transaction\n9  Exit";
    do
    {
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter account number for saving account: ";
            cin >> number;
            cout << "Enter initial balance for saving account: ";
            cin >> balance;
            cout << "Enter interest rate: ";
            cin >> rate;
            s = new saving_account(number, balance, rate);
            transaction_file = "saving_account_" + to_string(number) + "_transactions.txt";
            acc_counter++;
            cout<<endl<<"YOUR SAVINGS ACCOUNT HAS BEEN CREATED!"<<endl;
            break;
        case 2:
            cout << "Enter account number for current account: ";
            cin >> number;
            cout << "Enter initial balance for current account: ";
            cin >> balance;
            cout << "Enter overdraft limit: ";
            cin >> limit;
            c = new current_account(number, balance, limit);
            transaction_file = "current_account_" + to_string(number) + "_transactions.txt";
            acc_counter++;
            cout<<endl<<"YOUR CURRENT ACCOUNT HAS BEEN CREATED!"<<endl;
            break;
        case 3:
            if (s)
            {
                float deposit_amount;
                cout << "Enter deposit amount: ";
                cin >> deposit_amount;
                s->deposit(deposit_amount, transaction_file);
                cout<<endl<<"MONEY DEPOSITED TO SAVINGS ACCOUNT!"<<endl;
            }
            else
            {
                cout << "No saving account created." << endl;
            }
            break;
        case 4:
            if (s)
            {
                float withdraw_amount;
                cout << "Enter withdraw amount: ";
                cin >> withdraw_amount;
                s->withdraw(withdraw_amount, transaction_file);
                cout<<endl<<"MONEY WITHDRAWED FROM SAVINGS ACCOUNT!"<<endl;
            }
            else
            {
                cout << "No saving account created." << endl;
            }
            break;
        case 5:
            if (c)
            {
                float deposit_amount;
                cout << "Enter deposit amount: ";
                cin >> deposit_amount;
                c->deposit(deposit_amount, transaction_file);
                cout<<endl<<"MONEY DEPOSITED TO CURRENT ACCOUNT!"<<endl;
            }
            else
            {
                cout << "No current account created." << endl;
            }
            break;
        case 6:
            if (c)
            {
                float withdraw_amount;
                cout << "Enter withdraw amount: ";
                cin >> withdraw_amount;
                c->withdraw(withdraw_amount, transaction_file);
                cout<<endl<<"MONEY WITHDRAWED FROM CURRENT ACCOUNT!"<<endl;
            }
            else
            {
                cout << "No current account created." << endl;
            }
            break;
        case 7:
            show_transaction_history(transaction_file);
            break;
        case 8:
            if (s)
            {
                s->undo_last_transaction(transaction_file);
            }
            else if (c)
            {
                c->undo_last_transaction(transaction_file);
            }
            else
            {
                cout << "No account created." << endl;
            }
            break;
        case 9:
            cout << "Exiting system." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    while (choice != 9);
    delete s;
    delete c;
    cout<<endl<<"\n24CE058-Mahima Kukadiya"<<endl;
}
