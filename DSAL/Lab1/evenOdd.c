// Q3. Check even or odd
#include <stdio.h>
int main(){
    int a = 0;

    printf("Enter the value to be checked:\n");

    scanf("%d", &a);
    
    if (a % 2 == 0){
        printf("%d is an even number.\n", a);
    } else {
        printf("%d is an odd number.\n", a);
    }

    return 0;
}