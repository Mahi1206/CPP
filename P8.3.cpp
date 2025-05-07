/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
8.3 Standard Template Library � Remove duplicates with associative container.*/
#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int main()
{
    int n;
    // Ask for number of transactions
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> uniqueTransactions;  // Set to store unique transaction IDs

    cout << "Enter the transaction IDs: ";

    // Read transaction IDs and insert them into the set
    for (int i = 0; i < n; ++i)
    {
        int transactionID;
        cin >> transactionID;
        uniqueTransactions.insert(transactionID);  // Duplicates will be automatically removed
    }

    // Display the unique transaction IDs in sorted order
    cout << "\nUnique Transaction IDs: ";
    for (auto it = uniqueTransactions.begin(); it != uniqueTransactions.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
cout << "\n24CE058-Mahima Kukadiya\n";
    return 0;
}
