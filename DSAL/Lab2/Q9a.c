#include <stdio.h>

void swapArithmetic(int *a, int *b) {
    if (a == b) return; // Handle case where both pointers are the same
    
    *a = *a + *b;
    *b = *a - *b; 
    *a = *a - *b; 
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);

    swapArithmetic(&x, &y);
    
    printf("After swap:  x = %d, y = %d\n", x, y);
    return 0;
}