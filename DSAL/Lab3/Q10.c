#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}



bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize < 2) {
        return false;
    }


    qsort(nums, numsSize, sizeof(int), compare);

    // Check for adjacent duplicates
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true; // Found a duplicate
        }
    }

    return false; // No duplicates found
}

int main() {
    int nums1[] = {1, 2, 3, 1};
    int nums2[] = {1, 2, 3, 4};
    int nums3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    printf("Array {1, 2, 3, 1} contains duplicate: %s\n", 
           containsDuplicate(nums1, 4) ? "true" : "false");
    printf("Array {1, 2, 3, 4} contains duplicate: %s\n", 
           containsDuplicate(nums2, 4) ? "true" : "false");
    printf("Array {1, 1, ...} contains duplicate: %s\n", 
           containsDuplicate(nums3, 10) ? "true" : "false");

    return 0;
}