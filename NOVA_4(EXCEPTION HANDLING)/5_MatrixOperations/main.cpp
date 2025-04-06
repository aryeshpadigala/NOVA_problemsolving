#include <iostream>
#include <stdexcept>
#include "matrix.h"
using namespace std;

int main() 
{
    int matrix[3][3];
    int transposed[3][3];

    try {
        cout << "Enter the elements of a 3x3 matrix row by row:" << endl;

        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                cin >> matrix[i][j];

                if (cin.fail()) {
                    throw runtime_error("Invalid input — please enter integers only.");
                }
            }
        }

        cout << "Original Matrix:" << endl;
        displayMatrix(matrix);

        transposeMatrix(matrix, transposed);

        cout << "Transposed Matrix:" << endl;
        displayMatrix(transposed);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
