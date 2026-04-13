#include <cstdio>
#include "MyFunction.h"

template <typename T>
T Add(T a, T b)
{
    return a + b;
}


int main()
{
    int result = Add<int>(1, 2);
    float result2 = Add<float>(3.14f, 4.0f);
    
    int re = MyFunc(10, 20);
    printf("re = %d\n", re);
    
    return 0;
}
