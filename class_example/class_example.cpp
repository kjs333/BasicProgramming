#include <cstdio>

// public, private, protected => 접근지정자

// Simple class definition
class Person {
private:
    char name[50];
    int age;

public:
    
    // Default constructor
    Person() {
        const char* defaultName = "noname";
        int i = 0;
        while (defaultName[i] != '\0' && i < 49) {
            name[i] = defaultName[i];
            i++;
        }
        name[i] = '\0';
        age = 0;
        
        // char배열 복사하는 다른 방법들
        // 방법 1
        //strcpy(name, "noname");
        
        // 방법 2
        //strncpy(name, "noname", sizeof(name) - 1);
        //name[sizeof(name) - 1] = '\0';
        
        // 방법 3
        //snprintf(name, sizeof(name), "noname");
        
    }
    
    // Constructor 생성자
    Person(const char* n, int a) {
        int i = 0;
        while (n[i] != '\0' && i < 49) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
        age = a;
    }

    // Member function - Display info
    void displayInfo() {
        printf("Name: %s, Age: %d\n", name, age);
    }

    // Member function - Get name
    char* getName() {
        return name;
    }

    // Member function - Get age
    int getAge() {
        return age;
    }

    // Member function - Set age
    void setAge(int a) {
        age = a;
    }

    // Member function - Is adult
    bool isAdult() {
        return age >= 18;
    }
protected:
};

class Rectangle {
private:
    float width;
    float height;

public:
    // Constructor
    Rectangle(float w, float h) {
        width = w;
        height = h;
    }

    // Member function - Calculate area
    float getArea() {
        return width * height;
    }

    // Member function - Calculate perimeter
    float getPerimeter() {
        return 2 * (width + height);
    }

    // Member function - Display info
    void displayInfo() {
        printf("Width: %.2f, Height: %.2f\n", width, height);
        printf("Area: %.2f\n", getArea());
        printf("Perimeter: %.2f\n", getPerimeter());
    }

    // Member function - Is square
    bool isSquare() {
        return width == height;
    }
};

class Calculator {
private:
    int lastResult;

public:
    // Constructor
    Calculator() {
        lastResult = 0;
    }

    // Member function - Add
    int add(int a, int b) {
        lastResult = a + b;
        return lastResult;
    }

    // Member function - Subtract
    int subtract(int a, int b) {
        lastResult = a - b;
        return lastResult;
    }

    // Member function - Multiply
    int multiply(int a, int b) {
        lastResult = a * b;
        return lastResult;
    }

    // Member function - Divide
    float divide(int a, int b) {
        if (b != 0) {
            lastResult = a / b;
            return (float)a / b;
        }
        return 0;
    }

    // Member function - Get last result
    int getLastResult() {
        return lastResult;
    }
};

class Animal
{
    private: 

    protected:
    // 2순위 클래스 멤버 선언과 동시에 초기화
        int age = 10;
    
    public:
    // 1순위 생성자에서 초기화 => 멤버 이니셜라이저(가장 먼저 호출)
    Animal() : age(20)
    {
        // 3순위 생성자 함수 내부에서 초기화하는 방법
        age = 50;
    }
    // 보통 1순위인 멤버 이니셜라이저만 쓰고 멤버가 많으면 3순위 함수 내부에서 초기화하는 방법을 쓴다.
    
    void Print()
    {
        printf("Animal: age: %d\n", age);
    }
    
    //소멸자 : 객체가 파괴될 때 이 소멸자 함수가 호출된다.
    ~Animal()
    {
        printf("소멸자가 호출됨");
    }
};

int main() {
    printf("=== Simple Class Examples ===\n\n");

    // Person class example
    printf("[Person Class]\n");
    Person person1("John", 25);
    person1.displayInfo();
    printf("Is adult: %s\n\n", person1.isAdult() ? "Yes" : "No");

    Person person2("Alice", 17);
    person2.displayInfo();
    printf("Is adult: %s\n\n", person2.isAdult() ? "Yes" : "No");

    // Changing age using setter
    printf("[Using Setter Method]\n");
    printf("Before: ");
    person2.displayInfo();
    person2.setAge(18);
    printf("After setAge(18): ");
    person2.displayInfo();
    printf("\n");

    // Rectangle class example
    printf("[Rectangle Class]\n");
    Rectangle rect1(10.0f, 5.0f);
    rect1.displayInfo();
    printf("Is square: %s\n\n", rect1.isSquare() ? "Yes" : "No");

    Rectangle rect2(7.0f, 7.0f);
    rect2.displayInfo();
    printf("Is square: %s\n\n", rect2.isSquare() ? "Yes" : "No");

    // Calculator class example
    printf("[Calculator Class]\n");
    Calculator calc;

    printf("Add(10, 5) = %d\n", calc.add(10, 5));
    printf("Subtract(10, 3) = %d\n", calc.subtract(10, 3));
    printf("Multiply(4, 6) = %d\n", calc.multiply(4, 6));
    printf("Divide(20, 4) = %.2f\n", calc.divide(20, 4));
    printf("Last Result: %d\n\n", calc.getLastResult());

    // Array of objects
    printf("[Array of Objects]\n");
    Person people[3] = {
        Person("Tom", 20),
        Person("Jane", 22),
        Person("Mike", 19)
    };

    for (int i = 0; i < 3; i++) {
        printf("Person %d: ", i + 1);
        people[i].displayInfo();
    }
    printf("\n");

    // Dynamic object allocation
    printf("[Dynamic Object Allocation]\n");
    Person* pPerson = new Person("David", 30);
    printf("Name: %s\n", pPerson->getName());
    printf("Age: %d\n", pPerson->getAge());
    printf("Is adult: %s\n", pPerson->isAdult() ? "Yes" : "No");
    delete pPerson;
    pPerson = nullptr;
    printf("Memory freed\n\n");

    // Dynamic rectangle allocation
    printf("[Dynamic Rectangle Allocation]\n");
    Rectangle* pRect = new Rectangle(15.0f, 8.0f);
    pRect->displayInfo();
    delete pRect;
    pRect = nullptr;
    printf("Memory freed\n\n");

    // Multiple calculators
    printf("[Multiple Calculator Objects]\n");
    Calculator calc1;
    Calculator calc2;

    printf("Calculator 1: 5 + 3 = %d\n", calc1.add(5, 3));
    printf("Calculator 2: 10 * 2 = %d\n", calc2.multiply(10, 2));
    printf("Calc1 last result: %d\n", calc1.getLastResult());
    printf("Calc2 last result: %d\n\n", calc2.getLastResult());

    // Object comparison
    printf("[Object Comparison]\n");
    Rectangle r1(5.0f, 5.0f);
    Rectangle r2(6.0f, 4.0f);

    printf("Rectangle 1: ");
    r1.displayInfo();
    printf("Is square: %s\n\n", r1.isSquare() ? "Yes" : "No");

    printf("Rectangle 2: ");
    r2.displayInfo();
    printf("Is square: %s\n\n", r2.isSquare() ? "Yes" : "No");
    
    
    Animal a;
    a.Print();

    return 0;
}