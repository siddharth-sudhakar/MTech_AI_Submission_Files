// Search a Singly Linked List and Print the
// Element's Position.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void searchList(struct Node* head, int x){
    struct Node* current = head;
    int count = 1;
    int flag = 0;
    while(current != NULL){
        if(current->data == x){
            flag = 1;
            printf("Element found at position %d.\n", count);
        }
        current = current -> next;
        count++;
    }
    if(flag==0){
        printf("Element not found.\n");
    }
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    searchList(head, 70);

    struct Node* temp;
    while(head!= NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
