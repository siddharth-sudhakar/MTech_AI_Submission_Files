#include<stdio.h>
int main(){
    char username[] = "siddharthsudhakar@google.com"; //Some username
    
    int len = (int)(sizeof(username)/sizeof(username[0])) - 1;
    char reversed[len + 1];
    for (int i = 0; i < len; i++) {
        reversed[i] = username[len - i - 1];
    }
    reversed[len] = '\0'; // null terminate
    printf("Reversed username: %s\n", reversed);
}