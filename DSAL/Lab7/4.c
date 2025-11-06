#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char val;
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

void push(char val){
    Node* ptr = (Node*)malloc(sizeof(Node));

    if(ptr==NULL){
        printf("Unable to push element. Memory allocation failed.\n");
        return;
    }

    ptr->val = val;
    ptr->next = head;
    head = ptr;
    
    //printf("Item %c pushed to stack.\n", val);
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

    //printf("Item %c popped from stack.",item);
}

char peek(){
    if(head==NULL){
        printf("Stack is empty.\n");
        return '\0';
    }else{
        return head->val;
    }
}

bool isBalancedParantheses(char s[50]){
    int length=0;
    int i=0;
    while(s[i]!='\0'){
        length++;
        i++;
    }

    for(int i = 0; i < length; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        } else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(isEmpty()) return false;
            
            char top = peek();
            if((top == '(' && s[i] == ')') ||
               (top == '[' && s[i] == ']') ||
               (top == '{' && s[i] == '}')) {
                pop();
            } else {
                return false;
            }
        }
    }

    return isEmpty();
}

void clearStack(){
    while(!isEmpty()){
        pop();
    }
}

int main(){
    char test1[] = "()[]{}";
    char test2[] = "([{}])";
    char test3[] = "({[}])";
    char test4[] = "((()))";
    char test5[] = "((()";
    char test6[] = "{[()]}";
    char test7[] = "";
    char test8[] = "(]";
    
    printf("Testing: %s -> %s\n", test1, isBalancedParantheses(test1) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test2, isBalancedParantheses(test2) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test3, isBalancedParantheses(test3) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test4, isBalancedParantheses(test4) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test5, isBalancedParantheses(test5) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test6, isBalancedParantheses(test6) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test7, isBalancedParantheses(test7) ? "Balanced" : "Not Balanced");
    clearStack();
    
    printf("Testing: %s -> %s\n", test8, isBalancedParantheses(test8) ? "Balanced" : "Not Balanced");
    clearStack();
    
    return 0;
}