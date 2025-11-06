#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int val;
    struct node* next;
} Node;

//Define head pointer
Node* head = NULL;

bool isEmpty(){
    if(head==NULL)
        return true;
    else
        return false;
}

void push(int val){
    Node* ptr = (Node*)malloc(sizeof(Node));

    if(ptr==NULL){
        printf("Unable to push element. Memory allocation failed.\n");
        return;
    }

    ptr->val = val;
    ptr->next = head;
    head = ptr;
    
    printf("Item %d pushed to stack.\n", val);
}

void pop(){
    if(head==NULL){
        printf("Stack underflow!\n");
        return;
    }

    Node* ptr = head;
    int item = ptr->val;
    head = head->next;
    free(ptr);

    printf("Item %d popped from stack.\n",item);
}

int peek(){
    if(head==NULL){
        printf("Stack is empty.\n");
        return -1;
    }else{
        return head->val;
    }
}

void display(){
    if(head==NULL){
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Stack elements:\n");
    while(temp!=NULL){
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void clearStack(){
    while(!isEmpty()){
        pop();
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    display();

    int peekVal = peek();
    printf("The value from Peek is: %d\n", peekVal);

    clearStack();
    
    return 0;
}