#include <iostream>
#include <stdexcept>
#include "swap.h"
using namespace std;

int main() 
{
    try {
        int number1, number2;

        cout << "Enter the value of number1: ";
        cin >> number1;
        if (cin.fail()) throw invalid_argument("Invalid input for number1.");

        cout << "Enter the value of number2: ";
        cin >> number2;
        if (cin.fail()) throw invalid_argument("Invalid input for number2.");

        cout << "The numbers before swapping are:\nnumber1 = " << number1 << " and number2 = " << number2 << endl;

        swap(number1, number2);

        cout << "The numbers after swapping are:\nnumber1 = " << number1 << " and number2 = " << number2 << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
