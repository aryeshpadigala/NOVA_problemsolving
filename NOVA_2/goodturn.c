#include <stdio.h>

int is_good_turn(int chef_turn, int chefina_turn) {
    return (chef_turn + chefina_turn) > 6;
}

void process_test_cases(int test_cases) {
    int chef_turn, chefina_turn;
    for (int i = 0; i < test_cases; i++) {
        scanf("%d %d", &chef_turn, &chefina_turn);
        printf("%s\n", is_good_turn(chef_turn, chefina_turn) ? "YES" : "NO");
    }
}

int main() {
    int test_count;
    scanf("%d", &test_count);
    process_test_cases(test_count);
    return 0;
}
