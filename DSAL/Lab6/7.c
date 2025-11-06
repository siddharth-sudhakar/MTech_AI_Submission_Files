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
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (*head == NULL && position == 0) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    if (position == 0) {
        insertAtBeginning(head, data);
        free(newNode);  // Avoid memory leak
        return;
    }

    Node* temp = *head;
    int i = 0;
    while (i < position - 1 && temp->next != *head) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    printf("(HEAD)\n");
}

void freeList(Node* head) {
    if (head == NULL)
        return;

    Node* current = head->next;
    while (current != head) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(head);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtPosition(&head, 15, 2);
    insertAtPosition(&head, 20, 1);

    printf("Circular linked list:\n");
    traverse(head);

    freeList(head);
    return 0;
}