#include <cstdio>
#include "myHeader.h"

int main(int argc, char* argv[])
{
    int Sum = plus(100, 200);
    int A = sizeof(&Sum);
    printf("두 수의 합은 %d\n", Sum);
    return 0;
}
