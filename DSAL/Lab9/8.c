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

int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int isBalanced(Node* root) {
    if (!root) return 1;

    int lh = height(root->left);
    int rh = height(root->right);
    int bf = lh - rh;

    printf("Node %d → BF = %d\n", root->data, bf);

    if (bf > 1 || bf < -1)
        return 0;

    return isBalanced(root->left) && isBalanced(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {
    Node* A = newNode(10);
    A->left = newNode(5);
    A->right = newNode(15);
    A->left->left = newNode(3);
    A->left->right = newNode(7);

    printf("Testing Balanced Tree A:\n");
    inorder(A); printf("\n");
    printf("Is balanced? %s\n\n", isBalanced(A) ? "YES" : "NO");


    Node* B = newNode(10);
    B->left = newNode(5);
    B->left->left = newNode(3);
    B->left->left->left = newNode(1);

    printf("\nTesting Unbalanced Tree B:\n");
    inorder(B); printf("\n");
    printf("Is balanced? %s\n", isBalanced(B) ? "YES" : "NO");

    return 0;
}