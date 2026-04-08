#include <cstdio>

int plus(int num1, int num2) // num1, num2를 parameter
{
    return num1 + num2;
}

int main(int argc, char* argv[])
{
    int Sum = plus(1, 2); // 1, 2를 argument
    
    int Num = 0; //논리 주소를 하나(크기가 4byte) 할당 받는다.
    printf("Num 변수의 메모리 크기 = %d\n", sizeof(Num));
    int* Ptr = &Num; // Ptr이 Num의 주소를 가리키니까 Ptr을 통해서 값을 바꿀 수 있다.
    
    printf("Ptr 변수의 메모리 크기 = %d\n", sizeof(Ptr));
    
    
    printf("Num : %d\n",Num);
    printf("Num의 논리 주소 : %p\n", (void*)&Num);
    
    
    printf("=== Pointer Variables with Various Data Types ===\n\n");
    
    // int 포인터
    printf("[int Pointer]\n");
    int intValue = 42;
    int* intPtr = &intValue;
    printf("Value: %d\n", intValue);
    printf("Address: %p\n", (void*)intPtr);
    printf("Dereferenced value: %d\n\n", *intPtr);
    
    // float 포인터
    printf("[float Pointer]\n");
    float floatValue = 3.14f;
    float* floatPtr = &floatValue;
    printf("Value: %.2f\n", floatValue);
    printf("Address: %p\n", (void*)floatPtr);
    printf("Dereferenced value: %.2f\n\n", *floatPtr);
    
    // double 포인터
    printf("[double Pointer]\n");
    double doubleValue = 2.71828;
    double* doublePtr = &doubleValue;
    printf("Value: %.5f\n", doubleValue);
    printf("Address: %p\n", (void*)doublePtr);
    printf("Dereferenced value: %.5f\n\n", *doublePtr);
    
    // char 포인터
    printf("[char Pointer]\n");
    char charValue = 'A';
    char* charPtr = &charValue;
    printf("Value: %c\n", charValue);
    printf("Address: %p\n", (void*)charPtr);
    printf("Dereferenced value: %c\n\n", *charPtr);
    
    // short 포인터
    printf("[short Pointer]\n");
    short shortValue = 100;
    short* shortPtr = &shortValue;
    printf("Value: %d\n", shortValue);
    printf("Address: %p\n", (void*)shortPtr);
    printf("Dereferenced value: %d\n\n", *shortPtr);
    
    // long 포인터
    printf("[long Pointer]\n");
    long longValue = 123456789;
    long* longPtr = &longValue;
    printf("Value: %ld\n", longValue);
    printf("Address: %p\n", (void*)longPtr);
    printf("Dereferenced value: %ld\n\n", *longPtr);
    
    // long long 포인터
    printf("[long long Pointer]\n");
    long long longlongValue = 9876543210LL;
    long long* longlongPtr = &longlongValue;
    printf("Value: %lld\n", longlongValue);
    printf("Address: %p\n", (void*)longlongPtr);
    printf("Dereferenced value: %lld\n\n", *longlongPtr);
    
    // bool 포인터
    printf("[bool Pointer]\n");
    bool boolValue = true;
    bool* boolPtr = &boolValue;
    printf("Value: %d\n", boolValue);
    printf("Address: %p\n", (void*)boolPtr);
    printf("Dereferenced value: %d\n\n", *boolPtr);
    
    // unsigned int 포인터
    printf("[unsigned int Pointer]\n");
    unsigned int unsignedValue = 255;
    unsigned int* unsignedPtr = &unsignedValue;
    printf("Value: %u\n", unsignedValue);
    printf("Address: %p\n", (void*)unsignedPtr);
    printf("Dereferenced value: %u\n\n", *unsignedPtr);
    
    // Modifying values through pointers
    printf("[Modifying Values Through Pointers]\n");
    *intPtr = 99;
    printf("Modified int value: %d\n", intValue);
    
    *floatPtr = 2.71f;
    printf("Modified float value: %.2f\n", floatValue);
    
    *charPtr = 'Z';
    printf("Modified char value: %c\n", charValue);
    
    
    return 0;
}
