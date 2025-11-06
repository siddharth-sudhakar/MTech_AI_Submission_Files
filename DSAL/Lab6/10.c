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

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node* slow = head;
    Node* fast = slow->next;

    if (head == NULL)
        return;

    // Move fast by two and slow by one until fast reaches end
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    // Make the first half circular
    slow->next = *head1_ref;

    // Make the second half circular
    Node* current = *head2_ref;
    while (current->next != head) {
        current = current->next;
    }
    current->next = *head2_ref;
}

int main() {
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original circular linked list:\n");
    traverse(head);

    splitList(head, &head1, &head2);

    printf("\nFirst half:\n");
    traverse(head1);

    printf("\nSecond half:\n");
    traverse(head2);

    return 0;
}