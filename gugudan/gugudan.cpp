#include <cstdio>

int main() {
    printf("=== Multiplication Table (Gugudan) ===\n\n");

    // Example 1: Simple 2-9 times table
    printf("[Example 1: Simple Gugudan (2-9)]\n");
    for (int i = 2; i <= 9; i++) {
        printf("\n%d times table:\n", i);
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }

    printf("\n");
    return 0;
}
