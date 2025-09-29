#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    double salary;
    char department[20];
};

void increaseITSalaries(struct Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].department, "IT") == 0) {
            employees[i].salary *= 1.10; 
        }
    }
}

void displayEmployees(struct Employee employees[], int n) {
    printf("ID\tName\t\tSalary\t\tDepartment\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\t%s\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].department);
    }
}

int main() {
    struct Employee employees[] = {
        {101, "Alice", 70000, "HR"},
        {102, "Bob",   80000, "IT"},
        {103, "Charlie", 95000, "IT"},
        {104, "David", 65000, "Finance"}
    };
    int n = sizeof(employees) / sizeof(employees[0]);

    printf("--- Before Salary Increase ---\n");
    displayEmployees(employees, n);

    increaseITSalaries(employees, n);

    printf("\n--- After Salary Increase ---\n");
    displayEmployees(employees, n);

    return 0;
}