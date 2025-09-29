#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    // If loop completes without finding key, return -1
    return -1;
}

int main() {
    int customerIDs[] = {101, 204, 105, 303, 415, 502};


    int numCustomers = sizeof(customerIDs) / sizeof(customerIDs[0]);
    int searchID = 303;

    int result = linearSearch(customerIDs, numCustomers, searchID);
    if (result != -1) {
        printf("Customer ID %d found at index %d.\n", searchID, result);
    } else {
        printf("Customer ID %d not found.\n", searchID);
    }

    return 0;
}