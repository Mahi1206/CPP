/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
9.1 Error & Exception Handling � Handle invalid input and division by zero.*/
#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

int main()
{
    double loanAmount, income;

    // Input loan amount
    while (true)
    {
        cout << "Enter total loan amount: ";
        cin >> loanAmount;

        if (cin.fail() || loanAmount < 0)
        {
            cout << "Invalid input. Please enter a positive numeric value.\n";
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        } else {
            break;
        }
    }

    // Input annual income
    while (true)
    {
        cout << "Enter your annual income: ";
        cin >> income;

        if (cin.fail() || income <= 0)
        {
            cout << "Invalid input. Please enter a positive numeric value greater than zero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else
        break;

    }

    // Calculate and display ratio
    double ratio = loanAmount / income;
    cout << "\nLoan-to-Income Ratio: " << ratio << endl;

    cout << "\n24CE058-Mahima Kukadiya";
    return 0;
}
