#include <stdlib.h>

int num_compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** find_four_sum(int* numbers, int size, int target_sum, int* result_count, int** column_sizes) {
    qsort(numbers, size, sizeof(int), num_compare);
    int** quadruplets = (int**)malloc(1000 * sizeof(int*));  
    *column_sizes = (int*)malloc(1000 * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < size - 3; i++) {
        if (i > 0 && numbers[i] == numbers[i - 1]) continue;
        
        for (int j = i + 1; j < size - 2; j++) {
            if (j > i + 1 && numbers[j] == numbers[j - 1]) continue;
            
            int left = j + 1, right = size - 1;

            while (left < right) {
                long long sum = (long long)numbers[i] + numbers[j] + numbers[left] + numbers[right];

                if (sum == target_sum) {
                    quadruplets[*result_count] = (int*)malloc(4 * sizeof(int));
                    quadruplets[*result_count][0] = numbers[i];
                    quadruplets[*result_count][1] = numbers[j];
                    quadruplets[*result_count][2] = numbers[left];
                    quadruplets[*result_count][3] = numbers[right];

                    (*column_sizes)[*result_count] = 4;
                    (*result_count)++;
                    while (left < right && numbers[left] == numbers[left + 1]) left++;
                    while (left < right && numbers[right] == numbers[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < target_sum) {
                    left++;  
                }
                else {
                    right--; 
                }
            }
        }
    }

    return quadruplets;
}
