#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int lenOfList(Node* head) {
    Node* temp = head;
    int N = 0;
    if (head == NULL)
        return 0;
    while (temp) {
        N++;
        temp = temp->next;
    }
    return N;
}

Node* middleNode(Node* head, int N) {
    Node* temp = head;
    int count = 0;
    if (head == NULL)
        return NULL;
    while (count < N / 2 && temp != NULL) {
        count++;
        temp = temp->next;
    }
    return temp;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
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
    Node* head = newNode(10);
    Node* second = newNode(20);
    Node* third = newNode(30);
    Node* fourth = newNode(40);
    Node* fifth = newNode(50);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    printf("Doubly Linked List:\n");
    displayList(head);

    int N = lenOfList(head);
    printf("\nLength of the list: %d\n", N);

    Node* mid = middleNode(head, N);
    if (mid)
        printf("Middle node data: %d\n", mid->data);
    else
        printf("List is empty.\n");

    freeList(head);
    return 0;
}