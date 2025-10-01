#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[20];
};

int main() {
    int n = 3;

    // malloc
    struct Student *s1 = (struct Student *)malloc(n * sizeof(struct Student));

    // calloc
    struct Student *s2 = (struct Student *)calloc(n, sizeof(struct Student));

    printf("Using malloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll = %d\n", s1[i].roll);   // prints garbage
    }

    printf("\nUsing calloc:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll = %d\n", s2[i].roll);   // prints 0
    }

    free(s1);
    free(s2);
    return 0;
}