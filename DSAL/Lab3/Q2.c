#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int S) {
    int current_sum = arr[0];
    int start = 0;
    // Iterate from the second element
    for (int i = 1; i <= n; i++) {
        // While current_sum is greater than S, remove elements from the start
        while (current_sum > S && start < i - 1) {
            current_sum -= arr[start];
            start++;
        }

        // If current_sum equals S, we found the subarray
        if (current_sum == S) {
            printf("Subarray with sum %d found from index %d to %d.\n", S, start, i - 1);
            return;
        }

        // Add the current element to the window (if not past the end)
        if (i < n) {
            current_sum += arr[i];
        }
    }

    printf("No subarray with sum %d found.\n", S);
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    int S = 33;

    findSubarrayWithSum(arr, n, S);
    
    return 0;
}