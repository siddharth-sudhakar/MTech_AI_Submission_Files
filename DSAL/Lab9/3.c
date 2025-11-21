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

int isBSTUtil(Node* root, int min, int max) {
    if (root == NULL) return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(Node* root) {
    return isBSTUtil(root, -1000000000, 1000000000);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* A = newNode(8);

    A->left = newNode(3);
    A->right = newNode(10);
    A->left->left = newNode(1);
    A->left->right = newNode(6);

    printf("Tree A inorder: ");
    inorder(A);
    printf("\nIs Tree A a BST? %s\n\n", isBST(A) ? "YES" : "NO");

    Node* B = newNode(8);
    B->left = newNode(3);
    B->right = newNode(10);
    B->left->left = newNode(12);   // violating node

    printf("Tree B inorder: ");
    inorder(B);
    printf("\nIs Tree B a BST? %s\n", isBST(B) ? "YES" : "NO");

    return 0;
}
