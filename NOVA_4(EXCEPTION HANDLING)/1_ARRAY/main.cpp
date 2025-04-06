#include "array.h"
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = nullptr;

    try {
        arr = new int[size];
    } catch (bad_alloc& be) {
        cout << be.what() << " - Memory allocation failed in main\n";
        return 1;  
    }

    inputArray(arr, size);
    sortArray(arr, size);
    printArray(arr, size);

    int index;
    cout << "Enter an index to access value: ";
    cin >> index;

    int value = getValueAtIndex(arr, size, index);
    if (index >= 0 && index < size) {
        cout << "Value at index " << index << " is: " << value << endl;
    }

    delete[] arr;
    return 0;
}
