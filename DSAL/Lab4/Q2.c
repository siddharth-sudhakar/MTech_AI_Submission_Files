#include<stdio.h>
#include<string.h>

struct employee{
    int id;
    char Name[50];
    int salary;
};

int main(){
    struct employee arr[3] = {
        {1, "Siddharth", 20000},
        {2, "Harsha", 15000},
        {3, "Rohan", 10000}
    };

    for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i].id);
        printf("%s ", arr[i].Name);
        printf("%d\n", arr[i].salary);
    }
}