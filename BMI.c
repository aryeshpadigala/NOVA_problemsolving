#include <stdio.h>
float BMI(float height,float weight){
    return weight/(height*height);
}

int main() {
    float height = 1.82;
    float weight = 72;
    printf("%f",BMI(height,weight));
 
    return 0;
}
