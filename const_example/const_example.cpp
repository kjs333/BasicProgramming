#include <cstdio>


int main(int argc, char* argv[])
{
    // const int X = 10; // 아래와 동일
    int const X = 10;
    
    char szString[] = "Hello";
    char szString2[] = " World!";
    char* ptr = szString;
    
    
    const char* ptr2 = ptr; // 가리키는 값을 바꾸지 못한다.
    ptr2 = szString2; // 가능
    //ptr2[0] = 'K'; // 에러
    
    char* const ptr3 = ptr; // 다른 문자열을 가리키지 못한다.
    //ptr3 = szString2; // 에러
    ptr3[0] = 'W'; // 가능
    printf("%s", ptr);
    
    
    return 0;
}
