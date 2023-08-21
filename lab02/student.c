#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    int id;
    int age;
};

void printStudent (struct Student student) {
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Age: %d\n", student.age);
}

int main() {
    struct Student student;

    strcpy(student.name, "John");
    student.id = 10;
    student.age = 21;

    printStudent(student);
    
    return 0;
}
