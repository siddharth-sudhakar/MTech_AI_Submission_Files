// Q5. Simple Calculator (switch case)
#include <stdio.h>
int main(){
    float a = 0;
    float b = 0;
    float result = 0.00;
    char c;

    printf("Enter two numbers:\n");
    scanf("%f", &a);
    scanf("%f", &b);

    printf("Enter the operation you want to perform + or - or * or /:\n");
    scanf("%s", &c);

    switch(c){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
                break;
        case '/':
            result = a / b;
            break;
    }

    printf("The result is: %.2f\n", result);

    return 0;
}