/*THIS PROGRAM IS PREPARED BY 24CE058_Mahima Kukadiya
Manual Merge of Two Sorted Arrays Using Dynamic Memory in C++*/
#include <iostream>
using namespace std;

void mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int*& result, int& resultSize) {
    resultSize = size1 + size2;
    result = new int[resultSize];

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }
    while (i < size1) result[k++] = arr1[i++];
    while (j < size2) result[k++] = arr2[j++];
}
void inputArray(int*& arr, int size, const string& name) {
    arr = new int[size];
    cout << "Enter " << size << " sorted elements for " << name << " array:\n";
    for (int i = 0; i < size; ++i) {
        cout << name << "[" << i << "] = ";
        cin >> arr[i];
    }
}
void displayArray(int* arr, int size) {
    cout << "Merged Sorted Array: ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size1, size2;
    int *arr1 = nullptr, *arr2 = nullptr, *mergedArray = nullptr;
    int mergedSize;
    cout << "Enter size of first sorted array: ";
    cin >> size1;
    inputArray(arr1, size1, "First");
    cout << "Enter size of second sorted array: ";
    cin >> size2;
    inputArray(arr2, size2, "Second");
    mergeSortedArrays(arr1, size1, arr2, size2, mergedArray, mergedSize);
    displayArray(mergedArray, mergedSize);

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;

    cout<<"\n24CE058-Mahima Kukadiya\n";

    return 0;
}

