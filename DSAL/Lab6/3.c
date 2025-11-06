#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
}

Node* deleteAtStart(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        free(head);
        return NULL;
    }

    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

Node* deleteAtEnd(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    
    while(temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);

    return head;
}

Node* delValue(Node* head, int val){
    if(head==NULL)
        return NULL; 
    Node* temp = head;
    while(temp!=NULL && temp->data!=val){
        temp = temp->next;
    }
    if(temp==NULL)
        return head;
    if(temp==head){
        head = deleteAtStart(head);
        return head;
    }
    if(temp->next==NULL){
        head = deleteAtEnd(head);
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* node = newNode(data);

    if (head == NULL)
        return node;  // list empty, new node becomes head

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;

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
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 50);

    printf("Initial list:\n");
    displayList(head);

    head = delValue(head, 20);
    printf("After deleting repeated value 20:\n");
    displayList(head);

    head = delValue(head, 30);
    printf("After deleting non-repeated value 30:\n");
    displayList(head);

    head = delValue(head, 999);
    printf("After trying to delete value 999 (not there in list):\n");
    displayList(head);

    freeList(head);

    return 0;
}
