// Q11. Sum of digits

#include<stdio.h>

int main(){
    int n = 0;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);


    while(n>0){
        sum += n%10;
        n = n/10;
    }

    printf("The sum of digits is: %d\n", sum);
}