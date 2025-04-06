#include "array.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>  

using namespace std;

void inputArray(int* arr, int size) {
    try {
        if (arr == nullptr)
            throw std::bad_alloc();

        for (int i = 0; i < size; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    } catch (std::bad_alloc& be) {
        cout << be.what() << " - Memory allocation failed in inputArray\n";
    }
}

void sortArray(int* arr, int size) {
    sort(arr, arr + size);  
}

void printArray(int* arr, int size) {
    cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getValueAtIndex(int* arr, int size, int index) {
    try {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index is out of range");

        return arr[index];
    } catch (std::out_of_range& oor) {
        cout << oor.what() << " - Invalid index access\n";
    }
    return -1; 
}
