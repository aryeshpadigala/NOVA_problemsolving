#include <stdio.h>

int get_max_customers(int stoves, int minutes);

int main() {
    int stoves, minutes;
    scanf("%d %d", &stoves, &minutes);
    int result = get_max_customers(stoves, minutes);
    printf("%d\n", result);
    return 0;
}

int get_max_customers(int stoves, int minutes) {
    return stoves * minutes;
}
