#include <stdio.h>

int sentinelSearch(int arr[], int n, int key) {
    // Store the last element
    int last = arr[n - 1];
    
    arr[n - 1] = key;// Place the key at the last position

    int i = 0;
    // The loop now only has one comparison
    while (arr[i] != key) {
        i++;
    }

    
    arr[n - 1] = last; // Restore the original last element

    // Check if the key was found before the last element
    // or if the original last element was the key
    if ((i < n - 1) || (last == key)) {
        return i;
    }
    return -1;
}

int main() {
    int customerIDs[] = {101, 204, 105, 303, 415, 502};
    int numCustomers = sizeof(customerIDs) / sizeof(customerIDs[0]);
    int searchID = 415;

    int result = sentinelSearch(customerIDs, numCustomers, searchID);

    if (result != -1) {
        printf("Customer ID %d found at index %d.\n", searchID, result);
    } else {
        printf("Customer ID %d not found.\n", searchID);
    }

    return 0;
}