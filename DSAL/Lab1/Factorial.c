// Q6. Find the factorial of a number
#include <stdio.h>
int main(){
    int n=0;
    int result = 1;
    
    printf("Enter a number to find the factorial of:");
    scanf("%d", &n);

    for (int i = n; i >= 1 ; i--){
        result = result * i;
    }

    printf("The result is: %d\n", result);
    return 0;
}