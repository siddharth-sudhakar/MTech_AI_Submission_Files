#include <stdio.h>

void printNaturalRecursive(int n) {

    if (n <= 0) {
        return;
    }
    

    printNaturalRecursive(n - 1);
    
    printf("%d ", n);
}

int main() {
    int n = 10;
    printf("First %d natural numbers (using recursion): ", n);
    printNaturalRecursive(n);
    printf("\n");
    return 0;
}