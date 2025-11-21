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

Node* insertBST(Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int vals[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(vals) / sizeof(vals[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertBST(root, vals[i]);
    }

    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");

    return 0;
}