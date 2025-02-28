#include <stdbool.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int nums_size) {
    qsort(nums, nums_size, sizeof(int), cmpfunc);
    for (int i = 1; i < nums_size; i++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
}