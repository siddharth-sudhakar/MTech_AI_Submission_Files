#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct queue{
    int queue[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q){
    q->front = -1;
    q-> rear = -1;
}

bool isEmpty(Queue *q){
    return(q->front==-1);
}

bool isFull(Queue *q){
    return(q->rear==MAX_SIZE-1);
}

void enqueue(Queue *q, int data){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = data;
    printf("Enqueued %d in queue\n", data);
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    int data = q->queue[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    printf("Deleted element: %d\n", data);
    return data;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front;i<=q->rear;i++){
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Elements in the queue after enqueue operation: ");
    display(&q);

    dequeue(&q);
    printf("Elements in the queue after dequeue operation: ");
    display(&q);

    return 0;
}