#include<stdio.h>
#include<string.h>

typedef struct students{
    char name[50];
    int marks;
} stud;

int main(){
    int n, highestIdx = 0;
    printf("Enter the value of n:");
    scanf("%d", &n);

    stud arr[n];

    for(int i=0; i<n; i++){
        printf("Enter the name of student %d: ", i+1);
        scanf("%s",arr[i].name);
        printf("Enter the marks of student %d: ", i+1);
        scanf("%d",&arr[i].marks);
    }

    for(int i=0;i<n;i++){
        if(arr[i].marks>arr[highestIdx].marks){
            highestIdx = i;
        }
    }

    printf("The highest marks is %d, scored by %s", arr[highestIdx].marks,arr[highestIdx].name);
    return 0;
}