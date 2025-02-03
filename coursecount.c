#include <stdio.h>
//function to calculate the total number of courses
int course_count(int count) {
    return 2 * count;
}

int main() {
    int language_count;
    scanf("%d", & language_count);
if(language_count>0 && language_count<101)  printf("%d", course_count(language_count));//calls the function if conditon is satisfied
else printf("INVALID INPUT");
}