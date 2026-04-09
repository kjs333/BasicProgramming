
#include "Person.h"
#define MAX_PLAYER 8 // 매크로 상수

int main(int argc, char* argv[])
{
    Person person1 = {.name = "Alice", .age = 20, .height = 160.f, .gender = 'F'};
    Person* p = &person1;
    
    person1.Print();
    
    p->name; // 포인터 연산 + -> 로 멤버 함수 호출
    p->Print();
    return 0;
}
