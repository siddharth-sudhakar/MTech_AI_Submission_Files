#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int capacity) {
    CircularQueue *q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->size = 0;
    return q;
}

int isFull(CircularQueue *q) {
    return (q->size == q->capacity);
}

int isEmpty(CircularQueue *q) {
    return (q->size == 0);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", q->arr[q->front]);
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    if (q->size == 0)
        q->front = q->rear = -1;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    for (int count = 0; count < q->size; count++) {
        printf("%d -- ", q->arr[i]);
        i = (i + 1) % q->capacity;
    }
    printf("END\n");
}

void freeQueue(CircularQueue *q) {
    free(q->arr);
    free(q);
}

int main() {
    CircularQueue *q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);

    dequeue(q);
    display(q);

    freeQueue(q);

    return 0;
}