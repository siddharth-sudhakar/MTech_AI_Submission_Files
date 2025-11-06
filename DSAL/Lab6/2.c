#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
}

Node* insertAtBeginning(Node* head, int data){
    Node* node = newNode(data);
    node->next = head;
    if(head!=NULL) 
        head->prev = node;
    return node;
}

Node* insertAtEnd(Node* head, int data){
    Node* node = newNode(data);
    if(head==NULL)
        return node;
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}

Node* insertAtPos(Node* head, int position, int data){
    if(head == NULL && position==1)
        return newNode(data);
    if(head == NULL)
        return NULL;
    if(position == 1)
        return insertAtBeginning(head,data);
    
    int i=1;
    Node* temp = head;
    
    while(i<position-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }
    
    if(temp==NULL)
        return head;

    if(temp->next==NULL)
        return insertAtEnd(head, data);
    
    Node* node = newNode(data);
    

    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;

    return head;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial list:\n");
    displayList(head);

    head = insertAtPos(head, 1, 5);
    printf("After inserting 5 at position 1:\n");
    displayList(head);

    head = insertAtPos(head, 3, 15);
    printf("After inserting 15 at position 3:\n");
    displayList(head);

    head = insertAtPos(head, 6, 40);
    printf("After inserting 40 at last position:\n");
    displayList(head);

    head = insertAtPos(head, 10, 99);
    printf("After trying to insert 99 at position 10:\n");
    displayList(head);

    freeList(head);

    return 0;
}