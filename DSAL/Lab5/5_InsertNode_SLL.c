#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* node = newNode(data);
    node->next = head;
    return node; // new head
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* node = newNode(data);
    if (head == NULL)
        return node;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos == 1)
        return insertAtBeginning(head, data);

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    struct Node* node = newNode(data);
    node->next = temp->next;
    temp->next = node;
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


int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 20, 2);

    printf("Linked List after insertions:\n");
    printList(head);

    freeList(head);
    return 0;
}
