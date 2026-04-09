#include <cstdio>

// Base class with virtual function
class Animal {
protected:
    int age;
    int weight;

public:
    Animal(int a, int w) {
        age = a;
        weight = w;
    }

    // Virtual function
    virtual void makeSound() {
        printf("Animal makes a generic sound\n");
    }

    virtual void move() {
        printf("Animal moves\n");
    }

    void sleep() {
        printf("Animal is sleeping\n");
    }

    virtual void displayInfo() {
        printf("Age: %d, Weight: %d kg\n", age, weight);
    }

    virtual ~Animal() {}
};

// Derived class - Dog
class Dog : public Animal {
private:
    int barkVolume;

public:
    Dog(int a, int w, int v) : Animal(a, w) {
        barkVolume = v;
    }

    void makeSound() override {
        printf("Dog barks: Woof! Woof! (Volume: %d)\n", barkVolume);
    }

    void move() override {
        printf("Dog runs on four legs\n");
    }

    void displayInfo() override {
        printf("Dog - Age: %d, Weight: %d kg, Bark Volume: %d\n", age, weight, barkVolume);
    }

    ~Dog() override {}
};

// Derived class - Cat
class Cat : public Animal {
private:
    int meowFrequency;

public:
    Cat(int a, int w, int f) : Animal(a, w) {
        meowFrequency = f;
    }

    void makeSound() override {
        printf("Cat meows: Meow! Meow! (Frequency: %d Hz)\n", meowFrequency);
    }

    void move() override {
        printf("Cat walks on four legs\n");
    }

    void displayInfo() override {
        printf("Cat - Age: %d, Weight: %d kg, Meow Frequency: %d Hz\n", age, weight, meowFrequency);
    }

    ~Cat() override {}
};

// Derived class - Bird
class Bird : public Animal {
private:
    float flySpeed;

public:
    Bird(int a, int w, float s) : Animal(a, w) {
        flySpeed = s;
    }

    void makeSound() override {
        printf("Bird chirps: Tweet! Tweet! (Speed: %.1f km/h)\n", flySpeed);
    }

    void move() override {
        printf("Bird flies in the sky\n");
    }

    void displayInfo() override {
        printf("Bird - Age: %d, Weight: %d kg, Fly Speed: %.1f km/h\n", age, weight, flySpeed);
    }

    ~Bird() override {}
};

// Shape class - Abstract class
class Shape {
protected:
    int sides;

public:
    Shape(int s) {
        sides = s;
    }

    virtual void draw() = 0;

    virtual float getArea() = 0;

    virtual ~Shape() {}
};

// Circle class
class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : Shape(0) {
        radius = r;
    }

    void draw() override {
        printf("Drawing Circle with radius %.1f\n", radius);
    }

    float getArea() override {
        return 3.14159f * radius * radius;
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    float width;
    float height;

public:
    Rectangle(float w, float h) : Shape(4) {
        width = w;
        height = h;
    }

    void draw() override {
        printf("Drawing Rectangle with width %.1f and height %.1f\n", width, height);
    }

    float getArea() override {
        return width * height;
    }
};

// Triangle class
class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(float b, float h) : Shape(3) {
        base = b;
        height = h;
    }

    void draw() override {
        printf("Drawing Triangle with base %.1f and height %.1f\n", base, height);
    }

    float getArea() override {
        return 0.5f * base * height;
    }
};

int main() {
    printf("=== Virtual Function Examples (No Arrays) ===\n\n");

    // Example 1: Basic virtual function
    printf("[Example 1: Basic Virtual Function]\n");
    Animal animal(5, 20);
    animal.makeSound();
    animal.move();
    animal.sleep();
    printf("\n");

    // Example 2: Dog object
    printf("[Example 2: Dog Object]\n");
    Dog dog(3, 25, 80);
    dog.makeSound();
    dog.move();
    dog.sleep();
    printf("\n");

    // Example 3: Cat object
    printf("[Example 3: Cat Object]\n");
    Cat cat(2, 5, 2000);
    cat.makeSound();
    cat.move();
    cat.sleep();
    printf("\n");

    // Example 4: Bird object
    printf("[Example 4: Bird Object]\n");
    Bird bird(1, 1, 45.5f);
    bird.makeSound();
    bird.move();
    bird.sleep();
    printf("\n");

    // Example 5: Polymorphism with base class pointer
    printf("[Example 5: Polymorphism with Base Class Pointer]\n");
    Animal* animalPtr = &dog;
    printf("Pointer points to Dog:\n");
    animalPtr->makeSound();
    animalPtr->move();
    animalPtr->displayInfo();
    printf("\n");

    animalPtr = &cat;
    printf("Pointer points to Cat:\n");
    animalPtr->makeSound();
    animalPtr->move();
    animalPtr->displayInfo();
    printf("\n");

    animalPtr = &bird;
    printf("Pointer points to Bird:\n");
    animalPtr->makeSound();
    animalPtr->move();
    animalPtr->displayInfo();
    printf("\n");

    // Example 6: Dynamic polymorphism
    printf("[Example 6: Dynamic Polymorphism]\n");
    Dog dog2(4, 30, 90);
    Cat cat2(3, 4, 1500);

    Animal* ptr = &dog2;
    printf("ptr -> Dog:\n");
    ptr->displayInfo();
    printf("\n");

    ptr = &cat2;
    printf("ptr -> Cat:\n");
    ptr->displayInfo();
    printf("\n");

    // Example 7: Pure virtual functions (Abstract class)
    printf("[Example 7: Pure Virtual Functions\n");
    Circle circle(5.0f);
    Rectangle rect(10.0f, 8.0f);
    Triangle tri(6.0f, 4.0f);

    printf("Circle:\n");
    circle.draw();
    printf("Area: %.2f\n\n", circle.getArea());

    printf("Rectangle:\n");
    rect.draw();
    printf("Area: %.2f\n\n", rect.getArea());

    printf("Triangle:\n");
    tri.draw();
    printf("Area: %.2f\n\n", tri.getArea());

    // Example 8: Using base class pointers with shapes
    printf("[Example 8: Base Class Pointers with Shapes]\n");
    Shape* shapePtr = &circle;
    printf("ShapePtr -> Circle:\n");
    shapePtr->draw();
    printf("Area: %.2f\n\n", shapePtr->getArea());

    shapePtr = &rect;
    printf("ShapePtr -> Rectangle:\n");
    shapePtr->draw();
    printf("Area: %.2f\n\n", shapePtr->getArea());

    shapePtr = &tri;
    printf("ShapePtr -> Triangle:\n");
    shapePtr->draw();
    printf("Area: %.2f\n\n", shapePtr->getArea());

    // Example 9: Function with base class pointer parameter
    printf("[Example 9: Function with Base Class Pointer Parameter]\n");
    auto performAction = [](Animal* animal) {
        printf("Performing action:\n");
        animal->displayInfo();
        animal->makeSound();
        animal->move();
        printf("\n");
    };

    Dog dog3(2, 28, 75);
    Cat cat3(1, 3, 1800);
    Bird bird3(5, 2, 60.0f);

    performAction(&dog3);
    performAction(&cat3);
    performAction(&bird3);

    // Example 10: Virtual function with different behaviors
    printf("[Example 10: Virtual Function with Different Behaviors]\n");
    printf("All animals making sound:\n");
    dog.makeSound();
    cat.makeSound();
    bird.makeSound();
    printf("\n");

    printf("All animals moving:\n");
    dog.move();
    cat.move();
    bird.move();
    printf("\n");

    // Example 11: Comparison of virtual vs non-virtual
    printf("[Example 11: Virtual vs Non-Virtual Function]\n");
    Animal* ptr2 = &dog;
    printf("Virtual function (makeSound):\n");
    ptr2->makeSound();  // Calls Dog::makeSound

    printf("Non-virtual function (sleep):\n");
    ptr2->sleep();  // Calls Animal::sleep
    printf("\n");

    // Example 12: Multiple levels of inheritance
    printf("[Example 12: Polymorphic Behavior Demonstration]\n");
    printf("Creating different animals:\n");
    Dog d(3, 25, 85);
    Cat c(2, 5, 2000);
    Bird b(1, 1, 50.0f);

    printf("\nCalling makeSound on each:\n");
    Animal* animals[3] = {&d, &c, &b};
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }
    printf("\n");

    printf("Calling displayInfo on each:\n");
    for (int i = 0; i < 3; i++) {
        animals[i]->displayInfo();
        printf("\n");
    }

    // Example 13: Shape processing
    printf("[Example 13: Processing Different Shapes]\n");
    Circle c1(3.0f);
    Rectangle r1(5.0f, 4.0f);

    Shape* shapes[2] = {&c1, &r1};
    float totalArea = 0.0f;

    printf("Shapes and their areas:\n");
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        float area = shapes[i]->getArea();
        printf("Area: %.2f\n\n", area);
        totalArea += area;
    }
    printf("Total area: %.2f\n", totalArea);

    return 0;
}