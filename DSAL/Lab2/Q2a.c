#include<stdio.h>

int main(){
    int arr[] = {22,12,55,32,11,9};
    int max = 0;
    for (int i = 0; i<(sizeof(arr)/sizeof(arr[0])) ; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    printf("The max element is: %d\n", max);
}