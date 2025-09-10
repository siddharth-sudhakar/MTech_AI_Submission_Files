// Q20. Recursive binary search
#include <stdio.h>

int search(int a[], int l, int r, int x) {
    if(l > r) 
        return -1;

    int m = (l + r) / 2;


    if(a[m] == x) 
        return m;
    if(a[m] > x) 
        return search(a, l, m - 1, x);
    
    
    return search(a, m + 1, r, x);
}


int main() {
    int i, x;

    int n=7;

    int a[7] = {33,56,76, 102, 144, 156, 200};

    printf("Enter the ID to be searched: ");
    scanf("%d", &x);
    
    if (search(a, 0, n - 1, x) == -1){
        printf("The ID #%d is not in the array.\n",x);
        return 0;
    }
    printf("The ID #%d is at position %d in the array.\n",x , search(a, 0, n - 1, x));
    
    return 0;
}