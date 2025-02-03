#include <stdio.h>

int main() {
        int threshold_Limit, current_rate;
        scanf("%d %d", & threshold_Limit, & current_rate);

        if (current_rate > threshold_Limit) {//compares the current working rate with chef's threshold 
            printf("YES");// prints 'YES' if it exceeds with threshold
        } else {
            printf("NO");// prints 'NO' if chefs current rate under threshold
        }
        return 0;
}