#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size){
    for(int i=0; i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void partialSelectionSort(int arr[], int size, int k){
    for(int step = 0; step<k; step++){
        int min_idx = step;
        for(int i = step+1; i<size; i++){
            if(arr[i]<arr[min_idx]){
                min_idx = i; // Select minimum element
            }
        }
        swap(&arr[min_idx],&arr[step]); // Put minimum at the correct position
        printf("Array after iteration %d: \n", step+1);
        printArray(arr, size);
    }
}

int main(){
    int data[] = {2,12,14,4,1};
    int k = 3;
    int size = sizeof(data)/sizeof(data[0]);
    printf("Initial array: \n");
    printArray(data,size);
    partialSelectionSort(data, size, k);
    printf("\nFinal sorted array, with first %d elements sorted: \n", k);
    printArray(data,size);
}