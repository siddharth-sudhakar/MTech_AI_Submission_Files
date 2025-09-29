#include <stdio.h>
#include <string.h>

int countVowelsLookup(const char *str) {
    int is_vowel[256] = {0};

    is_vowel['a'] = 1; is_vowel['A'] = 1;
    is_vowel['e'] = 1; is_vowel['E'] = 1;
    is_vowel['i'] = 1; is_vowel['I'] = 1;
    is_vowel['o'] = 1; is_vowel['O'] = 1;
    is_vowel['u'] = 1; is_vowel['U'] = 1;

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_vowel[(unsigned char)str[i]]) {
            count++;
        }
    }

    return count;
}

int main() {
    char comment[] = "A USER comment with VOWELS.";
    int vowel_count = countVowelsLookup(comment);
    printf("The number of vowels is: %d\n", vowel_count);
    return 0;
}