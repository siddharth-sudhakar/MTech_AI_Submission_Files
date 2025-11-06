#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque *d = (Deque*)malloc(sizeof(Deque));
    d->arr = (int*)malloc(capacity * sizeof(int));
    d->front = -1;
    d->rear = 0;
    d->size = 0;
    d->capacity = capacity;
    return d;
}

int isFull(Deque *d) {
    return d->size == d->capacity;
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

void insertFront(Deque *d, int value) {
    if (isFull(d)) {
        printf("Deque is full\n");
        return;
    }
    if (d->front == -1) {
        d->front = d->rear = 0;
    } else {
        d->front = (d->front - 1 + d->capacity) % d->capacity;
    }
    d->arr[d->front] = value;
    d->size++;
}

void insertRear(Deque *d, int value) {
    if (isFull(d)) {
        printf("Deque is full\n");
        return;
    }
    if (d->front == -1) {
        d->front = d->rear = 0;
    } else {
        d->rear = (d->rear + 1) % d->capacity;
    }
    d->arr[d->rear] = value;
    d->size++;
}

void deleteFront(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", d->arr[d->front]);
    d->front = (d->front + 1) % d->capacity;
    d->size--;
    if (d->size == 0)
        d->front = -1, d->rear = 0;
}

void deleteRear(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from rear: %d\n", d->arr[d->rear]);
    d->rear = (d->rear - 1 + d->capacity) % d->capacity;
    d->size--;
    if (d->size == 0)
        d->front = -1, d->rear = 0;
}

void display(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return;
    }
    int i = d->front;
    printf("Deque: ");
    for (int count = 0; count < d->size; count++) {
        printf("%d ", d->arr[i]);
        i = (i + 1) % d->capacity;
    }
    printf("\n");
}

void freeDeque(Deque *d) {
    free(d->arr);
    free(d);
}

int main() {
    Deque *d = createDeque(5);
    insertRear(d, 10);
    insertRear(d, 20);
    insertFront(d, 5);
    insertFront(d, 1);

    display(d);
    
    deleteRear(d);
    display(d);
    
    deleteFront(d);
    display(d);
    
    insertRear(d, 25);
    insertFront(d, 0);
    display(d);
    
    freeDeque(d);
    
    return 0;
}