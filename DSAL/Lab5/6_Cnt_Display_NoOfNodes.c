// Count and Display Total Number of Nodes in a Linked List
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int countNodes(struct Node* head){
    struct Node* current = head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    
    int n;
    n = countNodes(head);
    printf("The number of nodes are: %d\n", n);

    freeList(head);
}