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

struct Node* delAtBeginning(struct Node* head){
    if(head == NULL) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* delAtEnd(struct Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while(current->next->next != NULL){
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
    return head;
}

struct Node* delAtGivenPos(struct Node* head, int pos){
    if(head == NULL) return NULL;
    if(pos == 1) return delAtBeginning(head);

    struct Node* current = head;
    for(int i=1;current!=NULL&&i<pos-1;i++){
        current=current->next;
    }

    if(current==NULL || current->next ==NULL) return head;

    struct Node* temp = current->next;
    current->next=current->next->next;
    free(temp);
    return head;
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

    printf("The linked list before any deletions:\n");
    printList(head);

    head = delAtBeginning(head);
    printf("The linked list after a deletion in the beginning:\n");
    printList(head);

    head = delAtEnd(head);
    printf("The linked list after a deletion at the end:\n");
    printList(head);

    printf("Enter the position where you want to delete the next node: ");
    int n = 0;
    scanf("%d",&n);

    head = delAtGivenPos(head, n);
    printf("The linked list after a deletion at position %d is:\n",n);
    printList(head);
    
    freeList(head);

    return 0;
}