//Q17. Fibonacci series using recursion

#include <stdio.h>


int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n, i;
    printf("Enter the number n: ");
    scanf("%d", &n);
    printf("The fibonacci series is: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}