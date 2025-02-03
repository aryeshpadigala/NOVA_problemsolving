#include <stdio.h>

#include <stdbool.h>

// Function to check if the daily water intake meets the requirement
bool isSufficientWaterIntake(int waterConsumed) {
    return waterConsumed >= 2000;
}

int main(void) {
    int testCases, waterConsumed;

    // Read the number of test cases
    scanf("%d", & testCases);

    while (testCases--) {
        scanf("%d", & waterConsumed);
        printf(isSufficientWaterIntake(waterConsumed) ? "YES\n" : "NO\n");
    }

    return 0;
}