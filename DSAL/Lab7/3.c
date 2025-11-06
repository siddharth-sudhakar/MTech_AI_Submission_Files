#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#define MAX_SIZE 50

typedef struct stack {
    int top;
    int capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity*sizeof(char));
    return stack;
}

bool isFull(Stack* stack){
    return stack->top==stack->capacity-1;
}

bool isEmpty(Stack* stack){
    return stack->top==-1;
}

void push(Stack* stack, char item){
    if(isFull(stack)){
        printf("Stack Overflow!\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = item;
    printf("%c pushed to stack.\n",item);
}

char pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

void display(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty!\n");
    } else {
        for(int i = stack->top; i>=0; i--){
            printf("%c\n",stack->array[i]);
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
    char name[50] = "Siddharth";
    int length=0;
    int i=0;
    while(name[i]!='\0'){
        length++;
        i++;
    }

    Stack* stack = createStack(MAX_SIZE);

    for(int i=0; i<length; i++){
        push(stack, name[i]);
    }

    printf("The stack after insertion is:\n");
    display(stack);

    for(int i=0; i<length; i++){
        name[i] = pop(stack);
    }

    printf("Reversed name: ");
    printf("%s\n", name);

    freeStack(stack);
    return 0;
}