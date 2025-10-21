// Create a singly linked list of n nodes and
// display all of its elements
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traverseLL(struct Node* head){
    struct Node* current = head;
    while(current->next!=NULL){
        printf("%d -> ", current->data);
        current=current->next;
    }
    printf("%d\n", current->data);
}

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    int n=0;
    printf("Enter the number of nodes to be created in the LL: ");
    scanf("%d",&n);

    if(n<=0){
        printf("The number should be positive.");
        return 0;
    }

    int val;
    printf("\nEnter value #1: ");
    scanf("%d", &val);

    struct Node* head = createNode(val);
    struct Node* temp = head;


    for(int i=1;i<n;i++){
        printf("\nEnter value #%d: ", i+1);
        scanf("%d", &val);
        temp->next = createNode(val);
        temp = temp->next;
    }

    printf("\n");
    printf("The nodes are:");

    traverseLL(head);
    
    struct Node* temp1;
    while(head!=NULL){
        temp1 = head;
        head = head->next;
        free(temp1);
    }
    return 0;
}