// 전처리기
#include <cstdio>
// 한줄짜리 주석
/* 
 main 함수란?
 모든 C/C++로 개발된 프로그램(exe)은 한 개 이상의 함수로 구성. 
 프로그램 실행시 진입점(Entry Point)을 알아야 하기 때문에
 이중 반드시 있어야하고, 단 하나만 존재하는 함수가 이 main함수
 당연히 이 main함수가 없으면 컴파일 자체가 안됨.
*/
int main()
{
    // Escape Sequence
    //printf("Hello World\n");
    //printf("Hello\tWorld");
    
    
    // 정수형 변수 선언
    int Num1 = 0;
    int Num2 = 0;
    
    // 입력
    scanf_s("%d", &Num1);
    scanf_s("%d", &Num2);
    
    
    //출력
    printf("Num1: %d\n", Num1);
    printf("Num2: %d\n", Num2);
    
    // 덧셈
    printf("Num1: %d + Num2: %d = %d\n", Num1, Num2, Num1 + Num2);
    // 뺄셈
    printf("Num1: %d - Num2: %d = %d\n", Num1, Num2, Num1 - Num2);
    // 곱셈
    printf("Num1: %d * Num2: %d = %d\n", Num1, Num2, Num1 * Num2);
    // 나눗셈
    printf("Num1: %d / Num2: %d = %d\n", Num1, Num2, Num1 / Num2);
    // 나머지 % (%는 한번 더 입력)
    printf("Num1: %d %% Num2: %d = %d\n", Num1, Num2, Num1 % Num2);
    
    return 0;
    
    
}
