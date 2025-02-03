#include <stdio.h>

#include<stdbool.h>

bool check_for_onefulpair(int a, int b) {
    return (a + b + (a * b) == 111);

}

int main() {
    int a, b;
    scanf("%d %d", & a, & b);
    if (check_for_onefulpair(a, b)) {
        printf("YES");
    }
    else {
        printf("NO");
    }
}