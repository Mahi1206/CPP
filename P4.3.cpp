/* THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
   4.3 INHERITANCE-MANAGING CAR INFO */
#include <iostream>
using namespace std;
class FuelType
{
protected:
    string fuel;
public:
    FuelType(string f)
    {
        fuel = f;
    }
    void displayFuel()
    {
        cout << "Fuel Type: " << fuel << endl;
    }
};
class Brand
{
protected:
    string brand;
public:
    Brand(string b)
    {
        brand = b;
    }
    void displayBrand()
    {
        cout << "Brand: " << brand << endl;
    }
};
class Car : public FuelType, public Brand
{
public:
    Car(string f, string b) : FuelType(f), Brand(b) {}
    void displayCarDetails()
    {
        displayBrand();
        displayFuel();
    }
};
int main()
{
    int numCars;
    cout << "Enter number of cars in service queue: ";
    cin >> numCars;
    Car* serviceQueue[100];
    for (int i = 0; i < numCars; i++)
    {
        string brand, fuel;
        cout << "\nEnter details for Car " << i + 1 << ":\n";
        cout << "Enter brand: ";
        cin >> ws;
        getline(cin, brand);

        cout << "Enter fuel type (e.g., Petrol, Diesel, Electric): ";
        cin >> ws;
        getline(cin, fuel);

        serviceQueue[i] = new Car(fuel, brand);
    }
    cout << "\nCAR DETAILS:";
    for (int i = 0; i < numCars; i++)
    {
        cout << "\nCar " << i + 1 << ":\n";
        serviceQueue[i]->displayCarDetails();
        delete serviceQueue[i];
    }
    cout<<endl<<"24CE058-Mahima Kukadiya";
}
