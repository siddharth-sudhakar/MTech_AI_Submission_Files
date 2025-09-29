#include <stdio.h>
#include <stdbool.h>

bool isPalindromeMath(int num) {
    if (num < 0 || (num % 10 == 0 && num != 0)) {
        return false;
    }

    int reversed_half = 0;

    while (num > reversed_half) {
        reversed_half = reversed_half * 10 + num % 10;
        num /= 10;
    }
    return num == reversed_half || num == reversed_half / 10;
}

int main() {
    int id1 = 12321;
    int id2 = 12345;
    int id3 = 1221;

    printf("ID %d is a palindrome: %s\n", id1, isPalindromeMath(id1) ? "true" : "false");
    printf("ID %d is a palindrome: %s\n", id2, isPalindromeMath(id2) ? "true" : "false");
    printf("ID %d is a palindrome: %s\n", id3, isPalindromeMath(id3) ? "true" : "false");
    return 0;
}