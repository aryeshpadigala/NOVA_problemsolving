#include <iostream>
#include "matrix.h"
using namespace std;
void displayMatrix(int matrix[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void transposeMatrix(int matrix[3][3], int transposed[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}