#include <stdio.h>

void swapXOR(int *a, int *b) {
    if (a == b) return; 

    *a = *a ^ *b;
    *b = *a ^ *b; 
    *a = *a ^ *b;
}

int main() {
    int x = 50, y = 95;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swapXOR(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);
    
    return 0;
}