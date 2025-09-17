#include<stdio.h>
int main(){
    int n[] = {10, 21, 42, 55, 66};
    int m = sizeof(n) / sizeof(n[0]);

    printf("\nChecking Even/Odd:\n");
    for (int i = 0; i < m; i++) {
        
        if ((n[i]&1) == 0)
            printf("%d is Even\n", n[i]);
        else
            printf("%d is Odd\n", n[i]);
    }
}