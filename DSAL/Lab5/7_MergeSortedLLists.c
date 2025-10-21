#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;  
};

struct Node* newNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeTwoLists(struct Node* head1,struct Node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    struct Node* curr1 = head1;
    struct Node* curr2 = head2;

    while(curr1 && curr2){
        struct Node* temp = NULL;
        if(curr1->data<curr2->data){
            //remove node from curr1 and append to result
            temp = curr1;
            curr1 = curr1->next;
            temp->next = NULL;

            if(head==NULL){
                //if the result LL is empty
                head = temp;
                tail = head;
            } else {
                //append new node after tail to the result
                tail->next = temp;
                tail = temp;
            }
        } else {
            //remove node from curr2 and append to result
            temp = curr2;
            curr2 = curr2->next;
            temp->next = NULL;

            if(head==NULL){
                //if the result LL is empty
                head = temp;
                tail = head;
            } else {
                //append new node after tail to the result
                tail->next = temp;
                tail = temp;
            }
        }
    }
    if(curr1){
        //append to result
        tail->next = curr1;
    }
    if(curr2){
        //append to result
        tail->next = curr2;
    }
    return head;
}

void printList(struct Node* node){
    while(node!=NULL){
        printf("%d -> ", node->data);
        node=node->next;
    }
    printf("NULL\n");
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
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);
    head1->next->next->next = newNode(7);

    struct Node* head2 = newNode(2);
    head2->next = newNode(4);
    head2->next->next = newNode(6);
    head2->next->next->next = newNode(8);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    // Merge them
    struct Node* mergedHead = mergeTwoLists(head1, head2);
    printf("Merged List: ");
    printList(mergedHead);

    freeList(mergedHead);
    return 0;
}