#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* a, struct Node* b) {
    // Base cases
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    struct Node* result = NULL;

    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

int main() {
    // first sorted list: 1 -> 3 -> 5
    struct Node* a = newNode(1);
    a->next = newNode(3);
    a->next->next = newNode(5);

    // second sorted list: 2 -> 4 -> 6
    struct Node* b = newNode(2);
    b->next = newNode(4);
    b->next->next = newNode(6);

    printf("List A: ");
    printList(a);
    printf("List B: ");
    printList(b);

    struct Node* merged = mergeLists(a, b);

    printf("Merged List: ");
    printList(merged);

    return 0;
}
