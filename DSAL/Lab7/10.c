#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *arr;
    int top;
    int capacity;
} Stack;

typedef struct {
    char *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Stack* createStack(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->arr = (char*)malloc(capacity * sizeof(char));
    s->capacity = capacity;
    s->top = -1;
    return s;
}

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (char*)malloc(capacity * sizeof(char));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

void push(Stack *s, char c) {
    if (s->top < s->capacity - 1)
        s->arr[++s->top] = c;
}

char pop(Stack *s) {
    return isStackEmpty(s) ? '\0' : s->arr[s->top--];
}

void enqueue(Queue *q, char c) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = c;
    q->size++;
}

char dequeue(Queue *q) {
    if (isQueueEmpty(q)) return '\0';
    char c = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return c;
}

int isPalindrome(char *str) {
    int n = strlen(str);
    Stack *s = createStack(n);
    Queue *q = createQueue(n);
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            push(s, str[i]);
            enqueue(q, str[i]);
        }
    }
    int palindrome = 1;
    while (!isStackEmpty(s) && !isQueueEmpty(q)) {
        if (pop(s) != dequeue(q)) {
            palindrome = 0;
            break;
        }
    }
    free(s->arr);
    free(q->arr);
    free(s);
    free(q);
    return palindrome;
}

int main() {
    char str[100]="naman";

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
    return 0;
}