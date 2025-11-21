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
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}


int kthSmallest(Node* root, int *k) {
    if (root == NULL) return -1;

    int left = kthSmallest(root->left, k);
    if (left != -1) return left;

    if (--(*k) == 0)
        return root->data;

    return kthSmallest(root->right, k);
}


int kthLargest(Node* root, int *k) {
    if (root == NULL) return -1;

    int right = kthLargest(root->right, k);
    if (right != -1) return right;

    if (--(*k) == 0)
        return root->data;

    return kthLargest(root->left, k);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


int main() {

    int vals[] = {15, 10, 20, 8, 12, 17, 25};
    int n = sizeof(vals)/sizeof(vals[0]);

    Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insertBST(root, vals[i]);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int k1 = 3;
    int ans1 = kthSmallest(root, &k1);
    printf("3rd smallest = %d\n", ans1);

    int k2 = 2;
    int ans2 = kthLargest(root, &k2);
    printf("2nd largest = %d\n", ans2);

    return 0;
}