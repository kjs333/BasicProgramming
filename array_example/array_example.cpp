#include <cstdio>

int main() {
    
    printf("=== Array and Pointer Examples ===\n\n");
   
    char szData[] = "Hello"; // char배열은  마지막에 '\0' 널문자가 들어가기 때문에 실제 6개의 원소가 들어간다.
    
    // Array declaration
    printf("[Array Declaration]\n");
    int arr[] = {10, 20, 30, 40, 50};
    // 배열 이름은 첫 원소의 주소를 가리킨다.
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < (int)size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Array and pointer relationship
    printf("[Array and Pointer Relationship]\n");
    int* ptr = arr;  // arr is equivalent to &arr[0]
    printf("arr[0]: %d\n", arr[0]);
    printf("*ptr: %d\n\n", *ptr);
    
    //**중요**
    printf("Array address: %p\n", (void*)arr);
    printf("&arr[0]: %p\n", (void*)&arr[0]);
    printf("Pointer address: %p\n\n", (void*)ptr);
    
    // Accessing array elements using pointer
    printf("[Accessing Array Elements Using Pointer]\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d, *(ptr+%d) = %d\n", i, arr[i], i, *(ptr + i));
    }
    printf("\n");
    
    // Pointer arithmetic
    printf("[Pointer Arithmetic]\n");
    printf("ptr points to: %d\n", *ptr);
    printf("ptr+1 points to: %d\n", *(ptr + 1));
    printf("ptr+2 points to: %d\n", *(ptr + 2));
    printf("ptr+3 points to: %d\n", *(ptr + 3));
    printf("ptr+4 points to: %d\n\n", *(ptr + 4));
    
    // Pointer increment
    printf("[Pointer Increment]\n");
    int* tempPtr = arr;
    printf("Initial pointer: %p, value: %d\n", (void*)tempPtr, *tempPtr);
    tempPtr++;
    printf("After ptr++: %p, value: %d\n", (void*)tempPtr, *tempPtr);
    tempPtr++;
    printf("After ptr++: %p, value: %d\n\n", (void*)tempPtr, *tempPtr);
    
    // Array of characters (string)
    printf("[Character Array (String)]\n");
    char str[] = "Hello";
    printf("String: %s\n", str);
    char* charPtr = str;
    printf("Using pointer: %s\n", charPtr);
    printf("First character: %c\n", *charPtr);
    printf("Second character: %c\n\n", *(charPtr + 1));
    
    // 2D array and pointer
    printf("[2D Array]\n");
    int arr2D[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("2D Array elements:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Pointer to 2D array
    printf("[2D Array Using Pointer]\n");
    int* ptr2D = (int*)arr2D;
    printf("First element: %d\n", *ptr2D);
    printf("Second element: %d\n", *(ptr2D + 1));
    printf("Fifth element: %d\n\n", *(ptr2D + 4));
    
    // Array of pointers
    printf("[Array of Pointers]\n");
    int a = 10, b = 20, c = 30;
    int* ptrArr[] = {&a, &b, &c};
    
    printf("Array of pointers:\n");
    for (int i = 0; i < 3; i++) {
        printf("ptrArr[%d] points to: %d\n", i, *ptrArr[i]);
    }
    printf("\n");
    
    // Modifying array through pointer
    printf("[Modifying Array Through Pointer]\n");
    int* modPtr = arr;
    *modPtr = 100;
    *(modPtr + 1) = 200;
    *(modPtr + 2) = 300;
    
    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}