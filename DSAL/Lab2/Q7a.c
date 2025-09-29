#include <stdio.h>

void printNaturalLoop(int n) {

    printf("First %d natural numbers: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n = 10;
    printNaturalLoop(n);
    return 0;
}