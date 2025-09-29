#include <stdio.h>
#include <limits.h>

void findSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return;
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Second pass to find the second largest element
    for (int i = 0; i < n; i++) {
        if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    
    if (secondLargest == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSecondLargest(arr, n);

    return 0;
}