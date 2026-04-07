#include <cstdio>

int main() {
    int score = 85;
    int age = 20;
    char grade = 'B';
    
    printf("=== Conditional Statement Examples ===\n\n");
    
    // if statement
    printf("[if Statement]\n");
    if (score >= 80) {
        printf("점수: %d - Pass!\n", score);
    }
    
    // if-else statement
    printf("\n[if-else Statement]\n");
    if (age >= 18) {
        printf("Age: %d - Adult\n", age);
    } else {
        printf("Age: %d - Minor\n", age);
    }
    
    // else-if statement
    printf("\n[if-else if-else Statement]\n");
    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }
    
    // switch statement
    printf("\n[switch Statement]\n");
    switch (grade) {
    case 'A':
        printf("Excellent!\n");
        break;
    case 'B':
        printf("Good!\n");
        break;
    case 'C':
        printf("Average!\n");
        break;
    default:
        printf("Try again!\n");
    }
    
    // ternary operator 삼항 연산자
    printf("\n[Ternary Operator]\n");
    printf("Status: %s\n", score >= 80 ? "Pass" : "Fail");
    
    // logical operators
    printf("\n[Logical Operators]\n");
    if (score >= 80 && age >= 18) {
        printf("You passed and you are an adult\n");
    }
    
    if (score < 70 || age < 18) {
        printf("Either score is low or you are a minor\n");
    } else {
        printf("Score is high and you are an adult\n");
    }
    
    // NOT operator
    printf("\n[NOT Operator]\n");
    if (!(score < 80)) {
        printf("Score is not less than 80\n");
    }
    
    return 0;
}