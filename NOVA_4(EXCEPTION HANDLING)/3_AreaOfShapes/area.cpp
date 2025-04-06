#include "area.h"
#include <stdexcept> 

const double PI = 3.141592653589793;

double calculateArea(double radius) 
{
    if (radius < 0) throw std::invalid_argument("Radius cannot be negative.");
    return PI * radius * radius;
}

double calculateArea(double length, double width) 
{
    if (length < 0 || width < 0)
        throw std::invalid_argument("Length and width cannot be negative.");
    return length * width;
}

double calculateArea(double base, double height, bool isTriangle) 
{
    if (base < 0 || height < 0)
        throw std::invalid_argument("Base and height cannot be negative.");
    if (isTriangle) 
    {
        return 0.5 * base * height;
    }
    return 0;
}
