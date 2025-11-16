#include <stdio.h>

#define MAX 100


typedef struct {
    int left;
    int mid;
    int right;
} Task;

typedef struct {
    Task data[MAX];
    int top;
} Stack;

void push(Stack *s, Task t) {
    s->data[++s->top] = t;
}

Task pop(Stack *s) {
    return s->data[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void stackMerge(int arr[], int left, int mid, int right) {
    Stack s;
    s.top = -1;

    // Push a single merge task (left half + right half)
    Task t = {left, mid, right};
    push(&s, t);

    // Process tasks using stack
    while (!isEmpty(&s)) {
        Task current = pop(&s);
        merge(arr, current.left, current.mid, current.right);
    }
}

int main() {
    int arr[] = {1, 4, 7, 2, 5, 6};
    int n = 6;

    printf("Before merge:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    stackMerge(arr, 0, 2, 5);

    printf("After merge:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}