// Q10. Count digits in a number

#include<stdio.h>
int main(){
    int n = 0;
    int counter = 0;

    printf("Enter a number: ");
    scanf("%d", &n);


    while(n>0){
        n = n/10;
        counter++;
    }

    printf("The number of digits is: %d\n", counter);
}