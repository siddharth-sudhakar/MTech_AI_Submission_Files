#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int h;
} Node;

Node* newNode(int key) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = key;
    t->left = t->right = NULL;
    t->h = 1;
    return t;
}

int height(Node* n) {
    return n ? n->h : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBF(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}


Node* rotateRight(Node* y) {
    printf("Rotation performed: RIGHT\n");

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->h = max(height(y->left), height(y->right)) + 1;
    x->h = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    printf("Rotation performed: LEFT\n");

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->h = max(height(x->left), height(x->right)) + 1;
    y->h = max(height(y->left), height(y->right)) + 1;

    return y;
}


Node* insertAVL(Node* root, int key) {
    if (root == NULL) return newNode(key);

    if (key < root->data)
        root->left = insertAVL(root->left, key);
    else if (key > root->data)
        root->right = insertAVL(root->right, key);
    else
        return root; // No duplicates

    // Update height
    root->h = 1 + max(height(root->left), height(root->right));

    // Balance factor
    int bf = getBF(root);
    printf("Node %d → BF = %d\n", root->data, bf);


    // Left Left
    if (bf > 1 && key < root->left->data)
        return rotateRight(root);

    // Right Right
    if (bf < -1 && key > root->right->data)
        return rotateLeft(root);

    // Left Right
    if (bf > 1 && key > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left
    if (bf < -1 && key < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {

    Node* root = NULL;


    int vals[] = {30, 20, 10, 25, 40, 50};
    int n = sizeof(vals) / sizeof(vals[0]);

    for (int i = 0; i < n; i++) {
        printf("\nInserting %d...\n", vals[i]);
        root = insertAVL(root, vals[i]);
    }

    printf("\nFinal AVL Tree (Inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}