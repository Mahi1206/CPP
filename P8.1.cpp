/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Reversing Numerical Sequences Using Iterators in Modern C++*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseWithIterators(vector<int>& nums) {
    auto start = nums.begin();
    auto end = nums.end() - 1;
    while (start < end) {
        iter_swap(start, end);
        ++start;
        --end;
    }
}

int main() {
    vector<int> numbers;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }
    vector<int> stdReversed = numbers;
    reverse(stdReversed.begin(), stdReversed.end());

    vector<int> manualReversed = numbers;
    reverseWithIterators(manualReversed);

    cout << "\nReversed using std::reverse(): ";
    for (int num : stdReversed) {
        cout << num << " ";
    }

    cout << "\nReversed using manual iterators: ";
    for (int num : manualReversed) {
        cout << num << " ";
    }

    cout<<"\n\n24CE058-Mahima Kukadiya\n";

    return 0;
}

