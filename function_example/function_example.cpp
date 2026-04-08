#include <cstdio>

void printHelloWorld() {
    printf("Hello World\n");
    return;
}

void printHelloWorld2(int a)
{
    printf("print : %d\n", a);
}

int mySum(int a, int b)
{
    int sum = a + b;
    printf("sum = %d\n", sum);
    return sum;
}

int main() {
    /*printf("=== Function Call Example ===\n\n");
    
    printf("Calling printHelloWorld function:\n");
    printHelloWorld();
    
    printf("\nCalling function multiple times:\n");
    for (int i = 1; i <= 3; i++) {
        printf("Call %d: ", i);
        printHelloWorld();
    }
    
    int temp = printHelloWorld2();
    printf("printHelloWorld returns %d\n", temp);
    
    int sum = mySum(1, 2);
    printf("sum = %d\n", sum);*/
    
    int a= 0;
    scanf_s("%d", &a); // & 는 변수의 "주소"를 나타내는 연산자
    printHelloWorld2(a);
    return 0;
}
