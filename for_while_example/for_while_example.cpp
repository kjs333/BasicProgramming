#include <cstdio>

int main() {
    printf("=== Loop Statement Examples ===\n\n");
    
    // for loop
    printf("[for Loop]\n");
    for (int i = 1; i <= 5; i++) { // ++은 1 증가 시킨다.
        printf("i = %d\n", i);
    }
    
    // for loop with step
    printf("\n[for Loop with Step]\n");
    for (int i = 0; i <= 10; i += 2) {
        printf("i = %d\n", i);
    }
    
    // while loop
    printf("\n[while Loop]\n");
    int count = 1;
    while (count <= 5) {
        printf("count = %d\n", count);
        count++;
    }
    
    // do-while loop
    printf("\n[do-while Loop]\n");
    int num = 1;
    do {
        printf("num = %d\n", num);
        num++;
    } while (num <= 5);
    
    // nested loop
    printf("\n[Nested Loop]\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
    
    // break statement
    printf("\n[break Statement]\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;
        }
        printf("i = %d\n", i);
    }
    printf("Loop ended at i = 5\n");
    
    // continue statement
    printf("\n[continue Statement]\n");
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;
        }
        printf("i = %d\n", i);
    }
    
    // range-based for loop (C++11+)
    printf("\n[Range-based for Loop]\n");
    int arr[] = {10, 20, 30, 40, 50};
    for (int value : arr) {
        printf("value = %d\n", value);
    }
    
    return 0;
}
