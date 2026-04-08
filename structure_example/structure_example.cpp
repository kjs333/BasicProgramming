#include <cstdio>
#include "Person.h"

int main() {
    printf("=== Structure Examples ===\n\n");
    
    // Basic structure usage
    printf("[Basic Structure]\n");
    Person person1;
    person1.age = 25;
    person1.height = 175.5f;
    person1.gender = 'M';
    snprintf(person1.name, sizeof(person1.name), "John");
    
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.1f cm\n", person1.height);
    printf("Gender: %c\n\n", person1.gender);
    
    person1.Print();
    
    // Multiple structures
    printf("[Multiple Structures]\n");
    Person person2;
    snprintf(person2.name, sizeof(person2.name), "Alice");
    person2.age = 23;
    person2.height = 162.0f;
    person2.gender = 'F';
    person2.Print();
    
    printf("Person 1: %s, Age %d\n", person1.name, person1.age);
    printf("Person 2: %s, Age %d\n\n", person2.name, person2.age);
    
    // Structure array
    printf("[Structure Array]\n");
    Student students[3];
    
    snprintf(students[0].name, sizeof(students[0].name), "Tom");
    students[0].studentID = 101;
    students[0].koreanScore = 85;
    students[0].mathScore = 90;
    students[0].englishScore = 88;
    
    snprintf(students[1].name, sizeof(students[1].name), "Jane");
    students[1].studentID = 102;
    students[1].koreanScore = 92;
    students[1].mathScore = 87;
    students[1].englishScore = 94;
    
    snprintf(students[2].name, sizeof(students[2].name), "Mike");
    students[2].studentID = 103;
    students[2].koreanScore = 78;
    students[2].mathScore = 85;
    students[2].englishScore = 80;
    
    for (int i = 0; i < 3; i++) {
        printf("ID: %d, Name: %s\n", students[i].studentID, students[i].name);
        printf("Korean: %d, Math: %d, English: %d\n", 
               students[i].koreanScore, students[i].mathScore, students[i].englishScore);
        int total = students[i].koreanScore + students[i].mathScore + students[i].englishScore;
        float average = total / 3.0f;
        printf("Total: %d, Average: %.2f\n\n", total, average);
    }
    
    // Structure size
    printf("[Structure Size]\n");
    printf("Size of Person: %zu bytes\n", sizeof(Person));
    printf("Size of Student: %zu bytes\n\n", sizeof(Student));
    
    // Structure pointer
    printf("[Structure Pointer]\n");
    Person* pPerson = &person1;
    printf("Using pointer - Name: %s\n", pPerson->name);
    printf("Using pointer - Age: %d\n", pPerson->age);
    printf("Using pointer - Height: %.1f cm\n\n", pPerson->height);
    
    // Modifying structure through pointer
    printf("[Modifying Structure Through Pointer]\n");
    pPerson->age = 26;
    printf("Modified age: %d\n\n", person1.age);
    
    // Nested structure example
    printf("[Structure Composition]\n");
    struct Address {
        char city[50];
        char street[50];
        int zipcode;
    };
    
    struct Employee {
        int employeeID;
        char name[50];
        Address address;
        float salary;
    };
    
    Employee emp;
    emp.employeeID = 1001;
    snprintf(emp.name, sizeof(emp.name), "David");
    snprintf(emp.address.city, sizeof(emp.address.city), "Seoul");
    snprintf(emp.address.street, sizeof(emp.address.street), "Main Street");
    emp.address.zipcode = 12345;
    emp.salary = 3500.50f;
    
    printf("Employee ID: %d\n", emp.employeeID);
    printf("Name: %s\n", emp.name);
    printf("City: %s\n", emp.address.city);
    printf("Street: %s\n", emp.address.street);
    printf("Zipcode: %d\n", emp.address.zipcode);
    printf("Salary: %.2f\n", emp.salary);
    
    return 0;
}