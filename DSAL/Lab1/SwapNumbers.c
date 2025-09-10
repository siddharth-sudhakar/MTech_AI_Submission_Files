//Q2. Swap two numbers
#include <stdio.h>
int main(){
    int a = 0;
    int b = 0;
    int temp = 0;

    printf("Enter the values of a and b\n");

    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("Entered values of a and b are: %d, %d\n", a, b);
    
    temp = b;
    b = a;
    a = temp;

    printf("Updated values of a and b are: %d, %d\n", a, b);
    return 0;
}