// Q9. Palindrome Check
#include<stdio.h>

int main(){
    int n = 0;
    int a = 0;
    int b = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    int temp = n;

    while(n>0){
        b = n%10;
        n = n/10;
        a = a*10 + b;
    }
    printf("Reversed number: %d\n", a);
    if (a == temp){
        printf("The entered number is a palindrome.\n");
    } else {
        printf("The entered number is NOT a palindrome.\n");
    }
}