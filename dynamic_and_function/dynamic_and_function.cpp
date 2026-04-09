#include <cstdio>
class Animal
{
    public:
    void Speak()
    {
        printf("Animal Sound\n");
    }
};

class Dog : public Animal
{
    public:
    void Speak()
    {
        printf("Dog bark\n");
    }
};

int main(int argc, char* argv[])
{
    Animal* pBase = new Animal;
    Animal* pDelete = pBase;
    Dog* pDog = new Dog;
    
    pDog->Speak();
    pBase = pDog;
    if (pBase == pDog)
    {
        pBase->Speak();
        // 정적 바인딩 (Static binding)
        // 이미 컴파일 단계에서 호출될 함수의 번지가 결정나는 것 { 컴파일 규정 }
        // 최초 "포인터의 타입"에 의해 함수가 선택된다.
        
        // 동적 바인딩 (Dynamic binding) 이라함.
        // 실행 시간(Runtime)에 호출될 함수의 번지를 결정.
        // 포인터의 타입과 상관없이 현재 포인터가 가리키는 객체의 타입에 의해 함수가 선택
    }
    return 0;
}
