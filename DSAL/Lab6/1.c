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
}

Node* insertAtBeginning(Node* head, int data){
    Node* node = newNode(data);
    node->next = head;
    if(head!=NULL) 
        head->prev = node;
    return node;
}

Node* insertAtEnd(Node* head, int data){
    Node* node = newNode(data);
    if(head==NULL)
        return node;
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}

Node* deleteAtStart(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        free(head);
        return NULL;
    }

    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

Node* deleteAtEnd(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    
    while(temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);

    return head;
}

Node* deleteAtPos(Node* head, int position){
    if(head==NULL){
        return NULL;
    }

    if(position==1){
        return deleteAtStart(head);
    }

    Node* temp = head;
    int i = 1;

    while(temp != NULL && i<position){
        temp = temp->next;
        i++;
    }

    if(temp==NULL){
        return head;
    }

    if(temp->next == NULL){
        return deleteAtEnd(head);
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;

}

void displayList(Node* head){
    Node* temp = head;
    while(temp){
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

int main(){
    Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Initial list:\n");
    displayList(head);

    head = deleteAtStart(head);
    printf("After deleting at start:\n");
    displayList(head);

    head = deleteAtEnd(head);
    printf("After deleting at end:\n");
    displayList(head);

    head = deleteAtPos(head, 2);
    printf("After deleting at position 2:\n");
    displayList(head);

    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 60);
    printf("After inserting at beginning and end:\n");
    displayList(head);

    freeList(head);

    return 0;
}