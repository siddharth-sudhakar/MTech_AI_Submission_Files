// Q19. Sum of digits using recursion

#include <stdio.h>


int sum(int n) {
    if(n == 0){
        return 0;
    }
    return n % 10 + sum(n / 10);
}

int main() {
    int n;

    printf("Enter a number n: ");
    scanf("%d", &n);
    printf("The sum is: %d\n", sum(n));
    return 0;
}