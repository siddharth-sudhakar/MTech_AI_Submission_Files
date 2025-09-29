#include <stdio.h>

// Helper function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    if (n == 0) return;
    k = k % n; // Handle cases where k > n
    if (k == 0) return;

    // 1. Reverse the entire array
    reverse(arr, 0, n - 1);
    // 2. Reverse the first k elements
    reverse(arr, 0, k - 1);
    // 3. Reverse the rest of the elements
    reverse(arr, k, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    

    printf("Original array: ");
    printArray(arr, n);

    rotateArray(arr, n, k);

    printf("Rotated array:  ");
    printArray(arr, n);

    return 0;
}