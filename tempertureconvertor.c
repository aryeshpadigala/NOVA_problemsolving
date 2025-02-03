#include <stdio.h>

float convertor(float temp_in_fahrenheit) {
    return (temp_in_fahrenheit - 32) * 5.0 / 9;
}

int main() {
    float temp_in_fahrenheit=98.3;
    printf("%f", convertor(temp_in_fahrenheit));
    return 0;
}