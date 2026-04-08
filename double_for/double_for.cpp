#include <cstdio>

int main() {
    printf("=== Nested for Loop and do-while Loop Examples ===\n\n");
    
    // Nested for loop - Multiplication table
    printf("[Nested for Loop - Multiplication Table]\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d*%d=%d  ", i, j, i * j);
        }
        printf("\n");
    }
    
    // Nested for loop - Pattern
    printf("\n[Nested for Loop - Triangle Pattern]\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // Nested for loop - Reverse pattern
    printf("\n[Nested for Loop - Reverse Triangle Pattern]\n");
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // do-while loop - Basic
    printf("\n[do-while Loop - Basic]\n");
    int count = 1;
    do {
        printf("count = %d\n", count);
        count++;
    } while (count <= 5);
    
    // do-while loop - User input simulation
    printf("\n[do-while Loop - Validation Example]\n");
    int number = 0;
    int attempt = 0;
    do {
        printf("Attempt %d: Please enter a number between 1 and 3: ", attempt + 1);
        number = 2;  // Simulating user input
        printf("%d\n", number);
        attempt++;
    } while (number < 1 || number > 3);
    printf("Valid number entered: %d\n", number);
    
    // do-while with break
    printf("\n[do-while Loop with break]\n");
    int x = 1;
    do {
        if (x == 3) {
            break;
        }
        printf("x = %d\n", x);
        x++;
    } while (x <= 10);
    
    // Nested for with do-while
    printf("\n[Nested for Loop with do-while]\n");
    for (int i = 1; i <= 3; i++) {
        int j = 1;
        do {
            printf("(%d,%d) ", i, j);
            j++;
        } while (j <= 3);
        printf("\n");
    }
    
    // do-while - At least one execution
    printf("\n[do-while - Executes at least once]\n");
    int value = 10;
    do {
        printf("This executes even though condition is false\n");
        printf("value = %d\n", value);
    } while (value < 5);  // Condition is false, but loop executed once
    
    return 0;
}