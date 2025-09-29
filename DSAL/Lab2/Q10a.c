#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

bool isPalindromeString(int num) {
    if (num < 0) return false;

    char str_num[20]; 

    sprintf(str_num, "%d", num);

    int left = 0;
    int right = strlen(str_num) - 1;

    while (left < right) {
        if (str_num[left] != str_num[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int id1 = 12321;
    int id2 = 12345;

    printf("ID %d is a palindrome: %s\n", id1, isPalindromeString(id1) ? "true" : "false");
    printf("ID %d is a palindrome: %s\n", id2, isPalindromeString(id2) ? "true" : "false");
    return 0;
}