// Q4. Find the largest of three numbers
#include <stdio.h>
int main(){
    int a = 0;
    int b = 0;
    int c = 0;

    printf("Enter the the numbers to find the largest out of:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    if (a > b){
        if (b > c){
            printf("%d is the largest number\n", a);
        } else {
            if (a > c){
                printf("%d is the largest number\n", a);
            } else {
                printf("%d is the largest number\n", c);
            }
        }
    } else {
        if (b > c){
            printf("%d is the largest number\n", b);
        } else {
            printf("%d is the largest number\n", c);
        }
    }
    return 0;
}