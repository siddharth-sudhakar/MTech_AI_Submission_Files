// Q7. Fibonacci Series (first n terms)
#include <stdio.h>
int main(){
    int n=0;
    
    printf("Enter the value of n:");
    scanf("%d", &n);

    int a = 0;
    int b = 1;
    int c = 0;
    printf("%d, ",a);
    printf("%d, ",b);

    for (int i=0; i<n-2; i++){
        c = a + b;
        printf("%d, ",c);
        a = b;
        b = c;
    }
    return 0;
}