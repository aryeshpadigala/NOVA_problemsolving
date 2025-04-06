#include <iostream>
#include <stdexcept>
#include "area.h"
using namespace std;

int main() 
{
    try {
        double radius, length, width, base, height;

        cout << "Enter the radius of the circle: ";
        cin >> radius;
        if (cin.fail() || radius < 0)
            throw invalid_argument("Invalid radius value");

        cout << "Area of the circle: " << calculateArea(radius) << endl;

        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
        if (cin.fail() || length < 0 || width < 0)
            throw invalid_argument("Invalid length or width value");

        cout << "Area of the rectangle: " << calculateArea(length, width) << endl;

        cout << "Enter the base and height of the triangle: ";
        cin >> base >> height;
        if (cin.fail() || base < 0 || height < 0)
            throw invalid_argument("Invalid base or height value");

        cout << "Area of the triangle: " << calculateArea(base, height, true) << endl;
    }
    catch (const exception& a) {
        cerr << "Error: " << a.what() << endl;
    }

    return 0;
}
