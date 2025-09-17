#include<stdio.h>

int sumOfElements(int arr[], int n){
	if(n==0){
    	return 0;
    }
    return arr[n-1]+sumOfElements(arr, n-1);
}

int main(){
	int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sumV = 0;
    sumV = sumOfElements(arr,n);
    printf("The sum is: %d\n", sumV);
}