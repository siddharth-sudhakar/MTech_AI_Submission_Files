#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    char* prefix = strs[0];
    int prefix_len = strlen(prefix);

    for (int i = 1; i < strsSize; i++) {

        while (strncmp(prefix, strs[i], prefix_len) != 0) {
            // Shorten the prefix by one character
            prefix_len--;
            if (prefix_len == 0) {
                return ""; // No common prefix found
            }
            prefix[prefix_len] = '\0'; // Null-terminate the shortened prefix
        }
    }
    return prefix;
}

int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    printf("LCP for {\"flower\", \"flow\", \"flight\"} is: \"%s\"\n", 
           longestCommonPrefix(strs1, 3));

    char* strs2[] = {"dog", "racecar", "car"};
    printf("LCP for {\"dog\", \"racecar\", \"car\"} is: \"%s\"\n", 
           longestCommonPrefix(strs2, 3));

    return 0;
}