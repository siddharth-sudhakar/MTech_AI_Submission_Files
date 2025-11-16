#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* newNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printLinkedList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swapNodes(node** head_ref, node* prevX, node* x, node* prevY, node* y) {
    // If x and y are same, nothing to do
    if (x == y)
        return;

    // Adjust previous nodes
    if (prevX != NULL)
        prevX->next = y;
    else
        *head_ref = y;

    if (prevY != NULL)
        prevY->next = x;
    else
        *head_ref = x;

    // Swap next pointers
    node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}

void SelectionSort(node** head_ref) {
    node *temp1 = *head_ref, *prev1 = NULL;

    // Outer loop: one node per pass
    while (temp1 != NULL) {
        node *minNode = temp1, *prevMin = prev1;
        node *temp2 = temp1->next, *prev2 = temp1;

        // Inner loop: find minimum in unsorted part
        while (temp2 != NULL) {
            if (temp2->data < minNode->data) {
                minNode = temp2;
                prevMin = prev2;
            }
            prev2 = temp2;
            temp2 = temp2->next;
        }

        // Swap if a smaller node was found
        if (minNode != temp1)
            swapNodes(head_ref, prev1, temp1, prevMin, minNode);

        // Move forward:
        // after swap, if minNode was ahead, temp1 is now at minNode’s position
        if (minNode == temp1)
            prev1 = temp1, temp1 = temp1->next;
        else {
            // after swapping, minNode now sits where temp1 was originally
            prev1 = minNode;
            temp1 = minNode->next;
        }
    }
}

int main() {
    node* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(5);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(3);

    printf("Original list:\n");
    printLinkedList(head);

    SelectionSort(&head);

    printf("Sorted list:\n");
    printLinkedList(head);

    return 0;
}