#include<stdio.h>
int main(){
    int n=4;
    int factorial=1;
    for(int i=1; i<=n; i++){
        factorial = factorial*i;
    }
    printf("The factorial of %d is: %d\n",n,factorial);
}