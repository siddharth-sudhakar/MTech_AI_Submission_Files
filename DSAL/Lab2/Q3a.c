#include<stdio.h>
int main(){
    char username[] = "siddharthsudhakar@google.com"; //Some username
    int l=0;
    int r = (int)(sizeof(username)/sizeof(username[0])) - 2;

    char temp;

    while(l<=r){
        temp = username[l];
        username[l] = username[r];
        username[r] = temp;
        l++;
        r--;        
    }
    printf("The reversed username is: %s\n", username);
}