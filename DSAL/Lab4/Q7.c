#include<stdio.h>
#include<string.h>

typedef struct player{
    char playerName[50];
    int runs;
    int wickets;
} Player;

int main(){
    Player arr[5]= {
        {"Rohit", 45, 1},
        {"Virat", 78, 0},
        {"Jadeja", 32, 3},
        {"Gill", 88, 0},
        {"Bumrah", 12, 4}
    };

    int topScorerIdx = 0;

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i].runs > arr[topScorerIdx].runs)
            topScorerIdx = i;
    }
    printf("The top scorer is %s, with %d runs.\n",arr[topScorerIdx].playerName,arr[topScorerIdx].runs);
    return 0;
}