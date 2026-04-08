
#include "myHeader.h"


int GlobalA = 50; //전역 변수

int main(int argc, char* argv[])
{
    int A = 100; // 지역 변수
    // 변수의 스코프(scope) : 영역, 생명주기
    printf("%d\n", A);
    printf("%d\n", GlobalA);
    
    {
        int C = -20;
        printf("%d\n", C);
    }
    
    return 0;
    //지역변수는 Stack space
}
