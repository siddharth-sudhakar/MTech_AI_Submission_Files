// Q12. Check prime number

#include <stdio.h>

int main(){
    int n = 0;
    int isPrime = 1;

    printf("Enter a number to check whether prime: ");
    scanf("%d", &n);

    if (n <= 1) {
        isPrime = 0;
    } else {
        for (int i = 2; i * i <= n; i++){
            if (n % i == 0){
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("It is a prime number\n");
    else
        printf("Not a prime number\n");

    return 0;
}
