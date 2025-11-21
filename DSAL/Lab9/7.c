#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;


Node* newNode(int val) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

Node* buildBalanced(int arr[], int l, int r) {
    if (l > r) return NULL;

    int mid = (l + r) / 2;
    Node* root = newNode(arr[mid]);

    root->left = buildBalanced(arr, l, mid - 1);
    root->right = buildBalanced(arr, mid + 1, r);

    return root;
}


void levelOrder(Node* root) {
    if (!root) return;

    Node* q[100];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        Node* node = q[front++];
        printf("%d ", node->data);

        if (node->left)
            q[rear++] = node->left;
        if (node->right)
            q[rear++] = node->right;
    }
}


int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBalanced(arr, 0, n - 1);

    printf("Level-order traversal of balanced BST: ");
    levelOrder(root);
    printf("\n");

    return 0;
}