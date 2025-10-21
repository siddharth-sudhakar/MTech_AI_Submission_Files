#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* node){
    while(node!=NULL){
        printf("%d -> ", node->data);
        node=node->next;
    }
    printf("NULL\n");
}

void printMiddleElem(struct Node* head){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* fast = head;
    struct Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("The middle element's value is: %d.\n", slow->data);
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
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(3);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(7);
    head->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next = newNode(9);

    printf("Original List: ");
    printList(head);

    printMiddleElem(head);
    freeList(head);
    
    return 0;
}