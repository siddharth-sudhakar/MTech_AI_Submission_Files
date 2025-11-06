#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Points to itself
    } else {
        Node* temp = *head;
        // Find the last node (the one pointing back to head)
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Self-loop
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to HEAD)\n");
}

void freeList(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head->next;
    while (temp != head) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(head);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);

    printf("Circular linked list:\n");
    traverse(head);

    freeList(head);
    return 0;
}