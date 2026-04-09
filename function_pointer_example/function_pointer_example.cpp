#include <cstdio>

typedef int ABCDE; // 매크로랑은 다름, 기존에 정의되어 있는 것을 바꾸는 것, 컴파일과정에서 변함. 타입재정의

typedef int (*Operation)(int, int);
// int형을 반환하고, 파라미터로 int형 변수 2개를 받는 함수 형식을 이제부터 Operation 이름을 쓰겠다.

// 함수의 시그니쳐(function Signature)
// => 함수 선언(Declaration)시 원형에 명시되는 매개변수(parameter) 리스트

typedef void(*EasyPrint) (void);

int Add (int a, int b)
{
    return a + b;
}

int Subtract (int a, int b)
{
    return a - b;
}

void Hello()
{
    printf("Hello\n");
}

void Bye()
{
    printf("Bye\n");
}

int main(int argc, char* argv[])
{
    Operation func = Add;
    func(1, 2);
    func = &Subtract;
    
    EasyPrint print = Hello;
    
    
    
    return 0;
}
