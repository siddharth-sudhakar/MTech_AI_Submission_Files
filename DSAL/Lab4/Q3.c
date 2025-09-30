#include<stdio.h>
#include<string.h>

struct student {
    int id;
    char name[50];
    struct d{
        int day, month, year;
    } dob;
};

int main(){
    struct student stud = {
        1, "Siddharth S", {12,6,2001}
    };

    printf("%d  %s  %d/%d/%d\n", stud.id, stud.name, stud.dob.day, stud.dob.month, stud.dob.year);
}