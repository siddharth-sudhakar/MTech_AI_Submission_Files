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


Node* findMin(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteAVL(Node* root, int key) {

    if (!root) return root;

    if (key < root->data)
        root->left = deleteAVL(root->left, key);

    else if (key > root->data)
        root->right = deleteAVL(root->right, key);

    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteAVL(root->right, temp->data);
        }
    }

    if (!root) return root;

    root->h = 1 + max(height(root->left), height(root->right));

    int bf = getBF(root);

    // Left Left
    if (bf > 1 && getBF(root->left) >= 0)
        return rotateRight(root);

    // Left Right
    if (bf > 1 && getBF(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right
    if (bf < -1 && getBF(root->right) <= 0)
        return rotateLeft(root);

    // Right Left
    if (bf < -1 && getBF(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int main() {
    Node* root = NULL;

    int insert_vals[] = {30, 20, 40, 10, 25, 35, 50};
    int n1 = sizeof(insert_vals)/sizeof(insert_vals[0]);

    printf("INSERTING\n");
    for (int i = 0; i < n1; i++) {
        printf("\nInsert %d:\n", insert_vals[i]);
        root = insertAVL(root, insert_vals[i]);
        printf("Tree Height = %d\n", height(root));
    }

    printf("\nFinal tree (Inorder): ");
    inorder(root);
    printf("\n\n");

    int delete_vals[] = {10, 40, 30};
    int n2 = sizeof(delete_vals)/sizeof(delete_vals[0]);

    printf("DELETING\n");
    for (int i = 0; i < n2; i++) {
        printf("\nDelete %d:\n", delete_vals[i]);
        root = deleteAVL(root, delete_vals[i]);
        printf("Tree Height = %d\n", height(root));
        printf("Inorder now: ");
        inorder(root);
        printf("\n");
    }

    return 0;
}