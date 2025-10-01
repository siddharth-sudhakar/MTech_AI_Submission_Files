#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[20];
};

int main() {
    int n, extra, i;
    struct Student *s;

    printf("Enter number of students: ");

    scanf("%d", &n);

    s = (struct Student *)malloc(n * sizeof(struct Student));

    printf("Enter details:\n");
    for (i = 0; i < n; i++) {
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
    }

    printf("\nEnter how many more students to add: ");
    scanf("%d", &extra);

    s = (struct Student *)realloc(s, (n + extra) * sizeof(struct Student));

    printf("Enter details of new students:\n");
    for (i = n; i < n + extra; i++) {
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
    }

    printf("\nAll Students:\n");
    
    for (i = 0; i < n + extra; i++) {
        printf("Roll: %d, Name: %s\n", s[i].roll, s[i].name);
    }

    free(s);

    return 0;
}