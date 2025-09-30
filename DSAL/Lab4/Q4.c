#include<stdio.h>

struct Node{
    int data;
    struct Node* next; 
};

int main(){
    struct Node node1;
    struct Node node2;

    node1.data = 100;
    node2.data = 200;

    node1.next = &node2;
    node2.next = NULL;

    printf("Node 1 data:%d\n", node1.data);
    printf("Node 2 data:%d\n", node1.next->data);

    return 0;
}