/*THIS PROGRAM IS PREPARED BY Mahima-24CE058
2.1 Reactangle Calculation*/
#include <iostream>
using namespace std;
class rectangle
{
    int length,width;
public:
    void dimensions(int l,int w)
    {
        length=l;
        width=w;
    }
    int area()
    {
       int area;
       area=length*width;
       return area;
    }
    int perimeter()
    {
        int peri;
        peri=2*(length+width);
        return peri;
    }
     void displaydetails()
    {
        cout << " Area: " << area() << "  Perimeter: " << perimeter() << endl;
    }
};
int main()
{
    rectangle r[50];
    int count = 0;
    char choice;
    do
    {
        double length, width;
        cout << "Enter length of rectangle: ";
        cin >> length;
        cout << "Enter width of rectangle: ";
        cin >> width;
        r[count].dimensions(length, width);
        count++;

        cout << "Do you want to add another rectangle? (y/n): ";
        cin >> choice;
    } while (choice == 'y' && count < 50);
    cout << "\nRectangle Details:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "Rectangle " << i + 1 << "- ";
        r[i].displaydetails();
    }
//To Update Any Rectangle's Dimension:
    char updatechoice;
    do
    {
        int index;
        cout << "Do you want to update any rectangle's dimensions? (y/n): ";
        cin >> updatechoice;
        if (updatechoice == 'y')
        {
            cout << "Enter rectangle number to update (1 to " << count << "): ";
            cin >> index;
            if (index > 0 && index <= count)
            {
                double newLength, newWidth;
                cout << "Enter new length: ";
                cin >> newLength;
                cout << "Enter new width: ";
                cin >> newWidth;
                r[index - 1].dimensions(newLength, newWidth);
                cout << "Updated details:" << endl;
                r[index - 1].displaydetails();
            }
            else
            {
                cout << "Invalid rectangle number!" << endl;
            }
        }
    } while (updatechoice == 'y');

    cout<<endl<<"THANK YOU!!"<<endl;
    cout<<"Mahima Kukadiya - 24CE058";

    return 0;
}


