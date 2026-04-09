#include <cstdio>

// Call by value - 값 전달
void incrementByValue(int value) {
    value++;
    printf("Inside function (by value): %d\n", value);
}

// Call by reference - 참조 전달
void incrementByReference(int& ref) {
    ref++;
    printf("Inside function (by reference): %d\n", ref);
}

// Pointer
void incrementByPointer(int* x)
{
    if (x != nullptr)
    {
        x++;
        printf("Inside function (by pointer): %d\n", *x);
    }
}

// Swap by value - 값으로는 안됨
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside function (by value): a=%d, b=%d\n", a, b);
}

// Swap by reference - 참조로는 가능
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside function (by reference): a=%d, b=%d\n", a, b);
}

// Modify array by value (배열은 항상 참조)
void modifyArrayByValue(int arr[]) {
    arr[0] = 999;
    printf("Inside function: arr[0]=%d\n", arr[0]);
}

// Pass pointer (포인터로 전달)
void modifyByPointer(int* ptr) {
    *ptr = 777;
    printf("Inside function (by pointer): *ptr=%d\n", *ptr);
}

// Multiple parameters - mix of value and reference
void processData(int value, int& ref, int* ptr) {
    value = 100;
    ref = 200;
    *ptr = 300;
    printf("Inside function - value:%d, ref:%d, *ptr:%d\n", value, ref, *ptr);
}

// Return by reference (주의: 지역변수 참조 반환 금지)
int& returnByReference(int& ref) {
    return ref;
}

// Function with const reference (읽기만 가능)
void displayByConstReference(const int& ref) {
    printf("Display (const reference): %d\n", ref);
    // ref++;  // 에러! const이므로 수정 불가
}

int main() {
    printf("=== Call by Value vs Call by Reference ===\n\n");

    // Example 1: Basic difference
    printf("[Example 1: Basic Difference]\n");
    int num = 5;
    printf("Original value: %d\n", num);

    printf("Calling incrementByValue(num):\n");
    incrementByValue(num);
    printf("After function: %d (unchanged)\n\n", num);

    printf("Calling incrementByReference(num):\n");
    incrementByReference(num);
    printf("After function: %d (changed!)\n\n", num);
    
    printf("Calling incrementByPointer(num):\n");
    incrementByPointer(&num);
    printf("After function: %d (changed!)\n\n", num);

    // Example 2: Swap function
    printf("[Example 2: Swap Function]\n");
    int x = 10, y = 20;
    printf("Before swap: x=%d, y=%d\n", x, y);

    printf("Swap by value:\n");
    swapByValue(x, y);
    printf("After swapByValue: x=%d, y=%d (unchanged)\n\n", x, y);

    printf("Swap by reference:\n");
    swapByReference(x, y);
    printf("After swapByReference: x=%d, y=%d (changed!)\n\n", x, y);

    // Example 3: Array (always by reference)
    printf("[Example 3: Array (Always by Reference)]\n");
    int arr[] = {1, 2, 3, 4, 5};
    printf("Before function: arr[0]=%d\n", arr[0]);
    printf("Calling modifyArrayByValue:\n");
    modifyArrayByValue(arr);
    printf("After function: arr[0]=%d (changed because arrays are by reference)\n\n", arr[0]);

    // Example 4: Pointer
    printf("[Example 4: Pointer\n");
    int ptr_num = 50;
    printf("Before function: ptr_num=%d\n", ptr_num);
    printf("Calling modifyByPointer:\n");
    modifyByPointer(&ptr_num);
    printf("After function: ptr_num=%d (changed)\n\n", ptr_num);

    // Example 5: Multiple parameters
    printf("[Example 5: Mixed Parameters (Value, Reference, Pointer)]\n");
    int val = 1, ref_val = 2, ptr_val = 3;
    printf("Before: val=%d, ref_val=%d, ptr_val=%d\n", val, ref_val, ptr_val);
    printf("Calling processData:\n");
    processData(val, ref_val, &ptr_val);
    printf("After: val=%d, ref_val=%d, ptr_val=%d\n", val, ref_val, ptr_val);
    printf("Note: Only reference and pointer changed!\n\n");

    // Example 6: Return by reference
    printf("[Example 6: Return by Reference]\n");
    int original = 42;
    int& ref = returnByReference(original);
    printf("Original: %d\n", original);
    printf("Reference: %d\n", ref);
    ref = 100;
    printf("After modifying reference: original=%d\n\n", original);

    // Example 7: Const reference (read-only)
    printf("[Example 7: Const Reference (Read-Only)]\n");
    int data = 123;
    printf("Calling displayByConstReference:\n");
    displayByConstReference(data);
    printf("Original value: %d (unchanged)\n\n", data);

    // Example 8: Reference in loop
    printf("[Example 8: Reference in Loop]\n");
    int numbers[] = {10, 20, 30, 40, 50};
    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Incrementing each element using reference:\n");
    for (int i = 0; i < 5; i++) {
        int& ref = numbers[i];
        ref += 5;
    }

    printf("Modified array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    // Example 9: Comparison table
    printf("[Comparison Table]\n");
    printf("%-20s | %-15s | %-15s\n", "Operation", "By Value", "By Reference");
    printf("-------------------------------------------------\n");
    printf("%-20s | %-15s | %-15s\n", "Memory", "Copy data", "Use same data");
    printf("%-20s | %-15s | %-15s\n", "Performance", "Slower", "Faster");
    printf("%-20s | %-15s | %-15s\n", "Original change?", "No", "Yes");
    printf("%-20s | %-15s | %-15s\n", "Syntax", "int x", "int& x");
    printf("\n");

    // Example 10: When to use
    printf("[When to Use]\n");
    printf("Use Call by Value:\n");
    printf("  - Small data types (int, float, char)\n");
    printf("  - You don't want to modify original\n");
    printf("  - Simple function with few parameters\n\n");

    printf("Use Call by Reference:\n");
    printf("  - Large objects (arrays, structures)\n");
    printf("  - You want to modify original\n");
    printf("  - Performance is critical\n");
    printf("  - Use const& for read-only access\n");

    return 0;
}