#include <stdio.h>
#include <string.h>
#include <ctype.h>


int countVowels(const char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char lower_char = tolower(str[i]);
        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' ||
            lower_char == 'o' || lower_char == 'u') {
            count++;
        }
    }


    return count;
}

int main() {
    char comment[] = "This is a user comment to analyze.";
    int vowel_count = countVowels(comment);
    printf("The number of vowels is: %d\n", vowel_count);
    return 0;
}