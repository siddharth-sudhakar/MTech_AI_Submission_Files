#include<stdio.h>
int main(){
	int arr[7] = {1,2,3,4,5,6,7};
    int sum = 0;
    for (int i = 0; i<7;i++){
    	sum = sum + arr[i];
    }
    printf("The sum is: %d\n", sum);
}