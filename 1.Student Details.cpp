#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    int age;
    float marks;
};

// Function to enter student details
void input(struct Student *s) {
    printf("Enter Roll No: ");
    scanf("%d", &s->roll);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Age: ");
    scanf("%d", &s->age);

    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

// Function to display student details
void display(struct Student *s) {
    printf("\n--- Student Details ---\n");
    printf("Roll No : %d\n", s->roll);
    printf("Name    : %s\n", s->name);
    printf("Age     : %d\n", s->age);
    printf("Marks   : %.2f\n", s->marks);
}

int main() {
    struct Student s[5];   // Array of structures
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        input(&s[i]);      // Passing pointer
    }

    printf("\n===== ALL STUDENTS =====\n");

    for (i = 0; i < n; i++) {
        display(&s[i]);    // Passing pointer
    }

    return 0;
}
