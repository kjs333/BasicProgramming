#include <cstdio>
struct Person {
    char name[50];
    int age;
    float height;
    char gender;
    
    void Print()
    {
        printf("%s %d %f %d", name, age, height, gender);
    }
};