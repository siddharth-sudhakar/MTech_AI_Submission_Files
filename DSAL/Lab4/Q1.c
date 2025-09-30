#include<stdio.h>
#include<complex.h>

typedef struct complexNums {
    double complex z1;
    double complex z2;
} myNums;

void swapNumbers(myNums* p){
    double complex temp = p->z1;
    p->z1 = p->z2;
    p->z2 = temp;
}

int main(){
    double complex a = 2.0 + 3.0*I;
    double complex b = 4.0 + 5.0*I;
    myNums pair = {a,b};

    swapNumbers(&pair);
    
    printf("The original numbers are %.2f + %.2fi and %.2f + %.2fi\n", creal(a), cimag(a), creal(b), cimag(b));
    printf("The numbers after swapping are:");
    printf("%.2f + %.2fi and %.2f + %.2fi.\n", creal(pair.z1), cimag(pair.z1), creal(pair.z2), cimag(pair.z2));

    return 0;

}