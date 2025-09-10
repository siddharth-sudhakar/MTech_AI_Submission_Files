// Q13. Array - Find Max Element

#include<stdio.h>

int main(){
    int A[6] = {3,7,8,21,33,4};
    int max = A[0];
    for (int i=0; i<6; i++){
        if (max < A[i]){
            max = A[i];
        }
    }
    printf("Max element is: %d\n", max);
}