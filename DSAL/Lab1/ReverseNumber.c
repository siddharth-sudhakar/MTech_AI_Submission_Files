// Q8. Reverse digits in a number

#include<stdio.h>

int main(){
    int n = 0;
    int a = 0;
    int b = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(n>0){
        b = n%10;
        n = n/10;
        a = a*10 + b;
    }
    printf("Reversed number: %d\n", a);
}