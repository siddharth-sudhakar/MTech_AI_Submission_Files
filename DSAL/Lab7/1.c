#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MAX_SIZE 50

typedef struct stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

bool isFull(Stack* stack){
    return stack->top==stack->capacity-1;
}

bool isEmpty(Stack* stack){
    return stack->top==-1;
}

void push(Stack* stack, int item){
    if(isFull(stack)){
        printf("Stack Overflow!\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = item;
    printf("%d pushed to stack.\n",item);
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

void display(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!\n");
    } else {
        for(int i = stack->top; i>=0; i--){
            printf("%d\n",stack->array[i]);
        }
    }
}

void freeStack(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);   
    }
}

int main(){
    Stack* stack = createStack(MAX_SIZE);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("%d popped from stack\n", pop(stack));
    printf("Top element is %d\n", peek(stack));

    printf("Elements present in stack:\n");
    display(stack);
    freeStack(stack);

    return 0;
}