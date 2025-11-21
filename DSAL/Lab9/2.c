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

Node* insertLevelOrder(Node* root, int val) {
    Node* temp = newNode(val);
    if (root == NULL) return temp;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* cur = queue[front++];

        if (cur->left == NULL) {
            cur->left = temp;
            break;
        } else {
            queue[rear++] = cur->left;
        }

        if (cur->right == NULL) {
            cur->right = temp;
            break;
        } else {
            queue[rear++] = cur->right;
        }
    }
    return root;
}

int height(Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int vals[] = {10, 5, 20, 3, 8};
    int n = sizeof(vals) / sizeof(vals[0]);

    for (int i = 0; i < n; i++) {
        root = insertLevelOrder(root, vals[i]);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int h = height(root);
    int leaves = countLeaves(root);

    printf("Height of tree = %d\n", h);
    printf("Number of leaf nodes = %d\n", leaves);

    return 0;
}