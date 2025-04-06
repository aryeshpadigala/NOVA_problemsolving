#include "char.h"
using namespace std;

int main() 
{
    try {
        char str[100];

        cout << "Enter a string: ";
        cin.getline(str, 100);

        if (cin.fail()) {
            throw runtime_error("Failed to read input.");
        }

        if (strlen(str) == 0) {
            throw invalid_argument("Empty string entered.");
        }

        toUpperCase(str);
        removeVowels(str);
        reverseString(str);

        cout << "The modified string is: " << str << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
