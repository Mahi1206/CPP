/*THIS PROGRAM IS PREPARED BY 24CE058-Mahima Kukadiya
2.4 INVENTORY MANANGEMENT SYSTEM*/
#include <iostream>
using namespace std;
class InventoryItem
{
    int itemID;
    string itemName;
    double price;
    int quantity;
public:
    // Default constructor
    InventoryItem()
    {
        itemID = 0;
        itemName = "Unknown";
        price = 0.0;
        quantity = 0;
    }
    // Parameterized constructor
    InventoryItem(int id, string name, double p, int qty)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = qty;
    }
    void addStock(int qty)
    {
        quantity += qty;
        cout << qty << " items added to stock." << endl;
    }
    void sellStock(int qty)
    {
        if (qty > quantity)
        {
            cout << "ERROR: Not enough stock available!" << endl;
        } else {
            quantity -= qty;
            cout << qty << " items sold." << endl;
        }
    }
    void displayItem()
    {
        cout << "Item ID: " << itemID << "\n"
             << "Name: " << itemName << "\n"
             << "Price: " << price << "\n"
             << "Quantity in stock: " << quantity << endl;
        cout << "-------------------------" << endl;
    }
    void setItemDetails(int id, string name, double p, int qty)
    {
        itemID = id;
        itemName = name;
        price = p;
        quantity = qty;
    }
};
int main()
{
    InventoryItem inventory[5];
    inventory[0] = InventoryItem(101, "Laptop", 750.99, 10);
    inventory[1] = InventoryItem(102, "Mouse", 25.50, 50);
    inventory[2] = InventoryItem(103, "Keyboard", 45.75, 30);
    inventory[3] = InventoryItem(104, "Monitor", 150.25, 20);
    inventory[4] = InventoryItem(); // Default item

    cout << "Initial Inventory:" << endl;
    for (int i = 0; i < 5; i++)
    {
        inventory[i].displayItem();
    }
    char choice;
    do
    {
        int index, operation, qty;
        cout << "Do you want to update inventory? (y/n): ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Enter item index (1 to " << 5 << "): ";
            cin >> index;
            if (index > 0 && index <= 5)
            {
                cout << "Choose operation: 1. Add Stock 2. Sell Item: ";
                cin >> operation;
                cout << "Enter quantity: ";
                cin >> qty;

                if (operation == 1)
                {
                    inventory[index - 1].addStock(qty);
                }
                else if (operation == 2)
                {
                    inventory[index - 1].sellStock(qty);
                }
                else
                {
                    cout << "Invalid operation!" << endl;
                }
                cout << "Updated Item Details:" << endl;
                inventory[index - 1].displayItem();
            }
            else
            {
                cout << "Invalid item index!" << endl;
            }
        }
    } while (choice == 'y');

    cout<<endl<<"Mahima Kukadiya - 24CE058";
    return 0;
}
