#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element *arr;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createQueue(int capacity) {
    PriorityQueue *q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->arr = (Element*)malloc(capacity * sizeof(Element));
    q->size = 0;
    q->capacity = capacity;
    return q;
}

int isFull(PriorityQueue *q) {
    return q->size == q->capacity;
}

int isEmpty(PriorityQueue *q) {
    return q->size == 0;
}

void enqueue(PriorityQueue *q, int data, int priority) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->size].data = data;
    q->arr[q->size].priority = priority;
    q->size++;
}

void dequeue(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int highest = 0;
    for (int i = 1; i < q->size; i++) {
        if (q->arr[i].priority > q->arr[highest].priority)
            highest = i;
    }
    printf("Dequeued: %d (Priority: %d)\n", q->arr[highest].data, q->arr[highest].priority);
    for (int i = highest; i < q->size - 1; i++)
        q->arr[i] = q->arr[i + 1];
    q->size--;
}

void display(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < q->size; i++)
        printf("(%d,%d) ", q->arr[i].data, q->arr[i].priority);
    printf("\n");
}

void freeQueue(PriorityQueue *q) {
    free(q->arr);
    free(q);
}

int main() {
    PriorityQueue *q = createQueue(10);
    enqueue(q, 5, 2);
    enqueue(q, 10, 1);
    enqueue(q, 3, 3);
    enqueue(q, 8, 2);

    printf("Initial queue:\n");
    display(q);

    dequeue(q);
    printf("After one dequeue:\n");
    display(q);

    dequeue(q);
    printf("After second dequeue:\n");
    display(q);

    freeQueue(q);
    return 0;
}
