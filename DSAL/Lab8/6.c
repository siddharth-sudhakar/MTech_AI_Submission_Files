#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(Queue* q) {
    return q->arr[q->front++];
}

int front(Queue* q) {
    return q->arr[q->front];
}

Queue mergeQueues(Queue* q1, Queue* q2) {
    Queue result;
    initQueue(&result);

    while (!isEmpty(q1) && !isEmpty(q2)) {
        if (front(q1) <= front(q2))
            enqueue(&result, dequeue(q1));
        else
            enqueue(&result, dequeue(q2));
    }

    // Add remaining elements
    while (!isEmpty(q1))
        enqueue(&result, dequeue(q1));
    while (!isEmpty(q2))
        enqueue(&result, dequeue(q2));

    return result;
}

void printQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    // Queue 1: 1 4 7
    enqueue(&q1, 1);
    enqueue(&q1, 4);
    enqueue(&q1, 7);

    // Queue 2: 2 3 6 8
    enqueue(&q2, 2);
    enqueue(&q2, 3);
    enqueue(&q2, 6);
    enqueue(&q2, 8);

    printf("Queue 1: ");
    printQueue(&q1);
    printf("Queue 2: ");
    printQueue(&q2);

    Queue merged = mergeQueues(&q1, &q2);

    printf("Merged Queue: ");
    printQueue(&merged);

    return 0;
}
