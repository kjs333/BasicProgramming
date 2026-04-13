
#include <cstdio>
#include <iostream>
using namespace std; // 이 cpp파일에서 std라는 namespace를 쓰겠다.

int GlovalValue = 300;
namespace A
{
    int Test;
}

namespace B
{
    int Test;
}

class Counter
{
private:
    int value;
    float price;

public:
    // 생성자
    Counter(int value)
    {
        // this 포인터를 사용해서 멤버 변수에 접근
        // 클래스 내부에서 자신을 가리키는 포인터
        this->value = value;
    }

    // 값 증가 함수
    void increment(int value)
    {
        // 매개변수와 멤버 변수 이름이 같을 때 this로 구분
        this->value += value;
        price = 100; // 이 경우에는 this포인터가 생략되어있다.
    }

    // 값 출력
    void print() const
    {
        static int N = 0; // 정적변수 -> global 영역에 저장됨.
        ++N;
        printf("this address is %p\n", (void *)this);
        printf("Current value: %d\n", this->value);
    }
};

//함수의 오버로딩(Overloading)
int MyAddFuncOver(int param1)
{
    return param1;
}

int MyAddFuncOver(int param1, int param2)
{
    return param1 + param2;
}

int MyAddFuncOver(int param1, int param2, int param3)
{
    return param1 + param2 + param3;
}

int main()
{
    Counter c(10);
    
    printf("c address is %p\n", (void *)&c);
    c.print();        // 10
    c.increment(5);
    c.print();        // 15
    
    A::Test = 400;
    B::Test = 300;

    return 0;
}
