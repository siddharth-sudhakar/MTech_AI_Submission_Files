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
    return node;
}

Node* ReverseDoublyLinkedList(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* curr = head;
    Node* temp = NULL;
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if(temp != NULL){
        head = temp->prev;
    }
    return head;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp){
        printf("%d <-> ", temp->data);
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
    Node* head = newNode(10);
    Node* second = newNode(20);
    Node* third = newNode(30);
    Node* fourth = newNode(40);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    printf("Original Doubly Linked List:\n");
    displayList(head);

    head = ReverseDoublyLinkedList(head);

    printf("Reversed Doubly Linked List:\n");
    displayList(head);

    freeList(head);
    return 0;
}
