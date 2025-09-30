#include<stdio.h>
#include<string.h>

typedef struct Student{
    char name[50];
    int marks;
} stud;

int main(){
    stud s1 = {"Rohan", 100};
    stud s2 = {"Siddharth", 100};

    if(strcmp(s1.name,s2.name)==0 && s1.marks==s2.marks)
        printf("The two students are the same.");
    else
        printf("The two students are not the same.");

    return 0;
}