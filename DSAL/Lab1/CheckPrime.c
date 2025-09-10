// Q12. Check prime number

#include <stdio.h>

int main(){
    int n = 0;
    printf("Enter a number to check whether prime: ");
    scanf("%d", &n);

    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            printf("Not a prime number\n");
        } else {
            printf("It is a prime number\n");
        }
    }
}