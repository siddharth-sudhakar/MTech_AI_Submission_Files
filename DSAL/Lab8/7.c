#include <stdio.h>

void selectionSort(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < end; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void hybridSort(int arr[], int n, int chunkSize) {
    for (int i = 0; i < n; i += chunkSize) {
        int end = (i + chunkSize < n) ? (i + chunkSize) : n;
        selectionSort(arr, i, end);
    }

    int step = chunkSize;
    while (step < n) {
        for (int i = 0; i + step < n; i += 2 * step) {
            int mid = i + step - 1;
            int rightEnd = (i + 2 * step - 1 < n) ? (i + 2 * step - 1) : (n - 1);
            merge(arr, i, mid, rightEnd);
        }
        step *= 2;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {9, 3, 7, 1, 4, 8, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chunkSize = 4;

    printf("Original array: ");
    printArray(arr, n);

    hybridSort(arr, n, chunkSize);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}