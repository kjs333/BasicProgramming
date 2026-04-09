#include <cstdio>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    printf("=== Function Pointer: With & vs Without & ===\n\n");

    // Method 1: Without & (implicit conversion)
    printf("[Method 1: Without & (Common)]\n");
    int (*fp1)(int, int);
    fp1 = add;  // 함수 이름이 자동으로 주소로 변환
    printf("fp1 = add\n");
    printf("fp1(5, 3) = %d\n", fp1(5, 3));
    printf("Address: %p\n\n", (void*)fp1);

    // Method 2: With & (explicit conversion)
    printf("[Method 2: With & (Also works)]\n");
    int (*fp2)(int, int);
    fp2 = &add;  // & 연산자로 명시적으로 주소 취득
    printf("fp2 = &add\n");
    printf("fp2(5, 3) = %d\n", fp2(5, 3));
    printf("Address: %p\n\n", (void*)fp2);

    // Both point to same address
    printf("[Comparison]\n");
    printf("fp1 address: %p\n", (void*)fp1);
    printf("fp2 address: %p\n", (void*)fp2);
    printf("fp1 == fp2: %s\n", (fp1 == fp2) ? "True (Same address)" : "False");
    printf("&add address: %p\n\n", (void*)&add);

    // Why both work
    printf("[Why Both Work]\n");
    printf("Function name 'add' decays to function pointer\n");
    printf("So both 'add' and '&add' refer to the same address\n");
    printf("add == &add: %s\n\n", (add == &add) ? "True" : "False");

    // Switching functions
    printf("[Switching Functions]\n");
    int (*fp)(int, int) = add;
    printf("Initial: fp = add, result = %d\n", fp(10, 5));

    fp = &subtract;  // & 붙임
    printf("After fp = &subtract, result = %d\n", fp(10, 5));

    fp = add;  // & 안붙임
    printf("After fp = add, result = %d\n\n", fp(10, 5));

    // With arrays
    printf("[Array of Function Pointers]\n");
    int (*ops1[2])(int, int) = {add, subtract};           // & 없음
    int (*ops2[2])(int, int) = {&add, &subtract};         // & 있음
    
    printf("ops1[0](20, 5) = %d\n", ops1[0](20, 5));
    printf("ops2[0](20, 5) = %d\n", ops2[0](20, 5));
    printf("Both work the same!\n\n");

    // Recommendation
    printf("[Recommendation]\n");
    printf("✓ Standard:  fp = add;      (without &)\n");
    printf("✓ Also OK:   fp = &add;     (with &)\n");
    printf("✓ Reason:    Function names automatically decay to pointers\n");
    printf("✓ Best practice: Use without & (more common in C++)\n");

    return 0;
}