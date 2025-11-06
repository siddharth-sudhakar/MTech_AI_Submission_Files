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

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
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

void deleteByValue(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* curr = *head;
    Node* prev = NULL;

    // if the head node itself contains the value
    if (curr->data == value) {
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
            return;
        }

        // find the last node
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        last->next = curr->next;  // Link last node to next of head
        *head = curr->next;       // Move head to next node
        free(curr);
        return;
    }

    // Deleting any node other than head
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != *head);

    printf("Value %d not found in the list.\n", value);
}

void freeList(Node* head) {
    if (head == NULL)
        return;

    Node* curr = head->next;
    while (curr != head) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(head);
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Original circular linked list:\n");
    traverse(head);

    deleteByValue(&head, 10);
    traverse(head);

    deleteByValue(&head, 30);
    traverse(head);

    deleteByValue(&head, 99);
    traverse(head);

    deleteByValue(&head, 20);
    deleteByValue(&head, 40);
    traverse(head);

    freeList(head);
    return 0;
}