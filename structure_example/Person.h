
// Structure definition
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

struct Student {
    int studentID;
    char name[50];
    int koreanScore;
    int mathScore;
    int englishScore;
    
    void Print()
    {
        printf("%d %s %d %d %d", studentID, name, koreanScore, mathScore, englishScore);
    }
};