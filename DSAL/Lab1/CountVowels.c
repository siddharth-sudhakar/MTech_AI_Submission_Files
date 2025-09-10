// Q14. Count vowels
#include<stdio.h>
int main(){
    char myString[] = "Hello, World!"; 
    int count = 0;
    for (int i=0; i<14; i++){
        if (myString[i] == 'a' || myString[i] == 'e' || myString[i] == 'i' || myString[i] == 'o' || myString[i] == 'u' || 
            myString[i] == 'A' || myString[i] == 'E' || myString[i] == 'O' || myString[i] == 'U'){
            count++;    
        }
    }
    printf("The number of vowels in the string is: %d\n", count);
}