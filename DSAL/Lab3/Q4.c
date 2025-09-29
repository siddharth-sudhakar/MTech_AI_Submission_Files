#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    int top_student_index = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[top_student_index].marks) {
            top_student_index = i;
        }
    }

    printf("\n--- Student with Highest Marks ---\n");
    printf("Name: %s\n", students[top_student_index].name);
    printf("Roll Number: %d\n", students[top_student_index].rollNumber);
    printf("Marks: %.2f\n", students[top_student_index].marks);

    return 0;
}