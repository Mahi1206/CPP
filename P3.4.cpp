/* THIS PROGRAM IS PREPARED BY 24CE058-Mahima Kukadiya
   3.4 USE OF FUNCTION TEMPLATES TO PERFORM OPERATIONS */
#include<iostream>
using namespace std;
template <typename T>
T maxof3(T x, T y, T z)
{
    T max_num = x;
    if (y > max_num) max_num = y;
    if (z > max_num) max_num = z;
    return max_num;
}
template <typename T>
void reversing(T x, T y, T z)
{
    cout << z << " " << y << " " << x << endl;
}
template <typename T>
void displaying_num(T x, T y, T z)
{
    cout << "First input: " << x << endl;
    cout << "Second input: " << y << endl;
    cout << "Third input: " << z << endl;
}
int main()
{
    int x, y, z;
    float x1, y1, z1;
    char x2, y2, z2;
    cout << "Enter 3 Integer Digits: "<<endl;
    cin >> x >> y >> z;
    cout << "Enter 3 Float Values: "<<endl;
    cin >> x1 >> y1 >> z1;
    cout << "Enter 3 Characters: "<<endl;
    cin >> x2 >> y2 >> z2;
    cout << "\nMaximum of all 3:\n";
    cout << "INTEGERS: " << maxof3<int>(x, y, z) << endl;
    cout << "FLOAT: " << maxof3<float>(x1, y1, z1) << endl;
    cout << "CHARACTERS: " << maxof3<char>(x2, y2, z2) << endl;
    cout << "\nReversed Order:\n";
    cout << "INTEGERS: ";
    reversing<int>(x, y, z);
    cout << "FLOAT: ";
    reversing<float>(x1, y1, z1);
    cout << "CHARACTERS: ";
    reversing<char>(x2, y2, z2);
    cout << "\nDisplayed Input Orders:\n";
    cout << "INTEGERS:\n";
    displaying_num<int>(x, y, z);
    cout << "FLOAT:\n";
    displaying_num<float>(x1, y1, z1);
    cout << "CHARACTERS:\n";
    displaying_num<char>(x2, y2, z2);

    cout<<endl<<"Mahima Kukadiya - 24CE058";
}
