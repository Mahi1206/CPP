/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima
1.2 Inventory Management System*/
#include <iostream>
using namespace std;
class Item
{
    int itemID;
    string itemName;
    int itemPrice;
    int totalPrice;
    int quantity;
public:
    void displayDetails()
    {
        cout << itemName << " " << itemPrice << " " << quantity << " " << totalPrice << endl;
    }
    int findItem(int id)
    {
        return (id == itemID);
    }
    void increaseQuantity()
    {
        quantity++;
        totalPrice = itemPrice * quantity;
        cout << "Item ID " << itemID << " Found! Added to basket. New quantity: " << quantity << " Total price: " << totalPrice << endl;
    }
    void addItem(int id)
    {
        cout << "New item found!" << endl;
        cout << "Enter item name: ";
        cin >> itemName;
        cout << "Enter item price: ";
        cin >> itemPrice;
        itemID = id;
        quantity = 1;
        totalPrice = itemPrice;
    }
    int getTotalPrice()
    {
        return totalPrice;
    }
};
int main()
{
    Item items[50];
    int itemCount = 0, id, totalAmount = 0;
    char choice;
start:
    cout << "Enter item ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < itemCount; i++)
    {
        if (items[i].findItem(id))
        {
            items[i].increaseQuantity();
            found = true;
            break;
        }
    }
    if (!found)
    {
        items[itemCount].addItem(id);
        itemCount++;
    }
    cout << "Do you want to add another item? (y/n): ";
    cin >> choice;
    if (choice == 'y')
    {
        goto start;
    }
    else
    {

        for (int i = 0; i < itemCount; i++)
        {
            totalAmount += items[i].getTotalPrice();
        }
        cout << endl << "Total Value Of All Products In The Inventory: " << totalAmount << endl;
        cout << endl << "THANKYOU!";
        cout << endl << "Mahima Kukadiya - 24CE058";
    }
    return 0;
}
