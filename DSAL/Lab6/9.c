#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

bool isCircular(Node* head) {
    if (head == NULL)
        return true;

    Node* curr = head->next;
    while (curr != head && curr != NULL) {
        curr = curr->next;
    }

    if (curr == head)
        return true;
    return false;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);
    head1->next->next->next = head1;

    if (isCircular(head1))
        printf("List 1 is circular.\n");
    else
        printf("List 1 is NOT circular.\n");
    // Test case 2: Non-Circular:
    Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = NULL; // Not circular

    if (isCircular(head2))
        printf("List 2 is circular.\n");
    else
        printf("List 2 is NOT circular.\n");
    return 0;
}
