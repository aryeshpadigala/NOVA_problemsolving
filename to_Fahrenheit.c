#include <stdio.h>

float convertor(float temp_in_Celsius) {
    return (temp_in_Celsius * 9.0/ 5) + 32;
}

int main() {
    float temp_in_Celsius=20.5;
    //scanf("%f",&temp_in_Celsius);
    printf("%f", convertor(temp_in_Celsius));
    return 0;
}