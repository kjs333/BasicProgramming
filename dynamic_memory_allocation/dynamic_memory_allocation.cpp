#include <cstdio>

int main() {
    printf("=== Dynamic Memory Allocation with nullptr Check ===\n\n");
    
    // Basic dynamic allocation with nullptr check
    printf("[Dynamic Allocation - Integer with Check]\n");
    int* ptr = new int;
    
    if (ptr != nullptr) {
        *ptr = 42;
        printf("Value: %d\n", *ptr);
        printf("Address: %p\n", (void*)ptr);
        delete ptr;
        ptr = nullptr;
        printf("Memory freed\n");
    } else {
        printf("Memory allocation failed!\n");
    }
    printf("\n");
    
    // Dynamic array with nullptr check
    printf("[Dynamic Array Allocation with Check]\n");
    int size = 5;
    int* arr = new int[size];
    
    if (arr != nullptr) {
        for (int i = 0; i < size; i++) {
            arr[i] = (i + 1) * 10;
        }
        
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        delete[] arr;
        arr = nullptr;
        printf("Array memory freed\n");
    } else {
        printf("Memory allocation failed!\n");
    }
    printf("\n");
    
    // Dynamic struct with nullptr check
    printf("[Dynamic Struct Allocation with Check]\n");
    struct Person {
        char name[50];
        int age;
    };
    
    Person* pPerson = new Person();
    
    if (pPerson != nullptr) {
        pPerson->name[0] = 'J';
        pPerson->name[1] = 'o';
        pPerson->name[2] = 'h';
        pPerson->name[3] = 'n';
        pPerson->name[4] = '\0';
        pPerson->age = 25;
        
        printf("Name: %s\n", pPerson->name);
        printf("Age: %d\n", pPerson->age);
        delete pPerson;
        pPerson = nullptr;
        printf("Struct memory freed\n");
    } else {
        printf("Memory allocation failed!\n");
    }
    printf("\n");
    
    // Dynamic struct array with nullptr check
    printf("[Dynamic Struct Array with Check]\n");
    int numPersons = 3;
    Person* persons = new Person[numPersons];
    
    if (persons != nullptr) {
        const char* names[] = {"Tom", "Jane", "Mike"};
        int ages[] = {20, 23, 25};
        
        for (int i = 0; i < numPersons; i++) {
            int j = 0;
            while (names[i][j] != '\0') {
                persons[i].name[j] = names[i][j];
                j++;
            }
            persons[i].name[j] = '\0';
            persons[i].age = ages[i];
        }
        
        for (int i = 0; i < numPersons; i++) {
            printf("Person %d: %s, Age %d\n", i + 1, persons[i].name, persons[i].age);
        }
        delete[] persons;
        persons = nullptr;
        printf("Struct array memory freed\n");
    } else {
        printf("Memory allocation failed!\n");
    }
    printf("\n");
    
    // Dynamic 2D array with nullptr check
    printf("[Dynamic 2D Array with Check]\n");
    int rows = 3, cols = 3;
    int** matrix = new int*[rows];
    
    if (matrix != nullptr) {
        bool allocationSuccess = true;
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            if (matrix[i] == nullptr) {
                allocationSuccess = false;
                break;
            }
        }
        
        if (allocationSuccess) {
            int value = 1;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = value++;
                }
            }
            
            printf("2D Array:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
                matrix[i] = nullptr;
            }
            delete[] matrix;
            matrix = nullptr;
            printf("2D Array memory freed\n");
        } else {
            printf("2D Array row allocation failed!\n");
            delete[] matrix;
        }
    } else {
        printf("2D Array allocation failed!\n");
    }
    printf("\n");
    
    // Check if pointer is nullptr after deletion
    printf("[Verify nullptr After Deletion]\n");
    int* testPtr = new int(100);
    printf("Before delete: ptr = %p\n", (void*)testPtr);
    delete testPtr;
    testPtr = nullptr;
    printf("After delete and assignment: ptr = %p\n", (void*)testPtr);
    
    if (testPtr == nullptr) {
        printf("Pointer is safely nullptr\n");
    }
    
    return 0;
}