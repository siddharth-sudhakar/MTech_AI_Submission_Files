//Write a program to construct a binary tree using user input (level-order insertion).
//Perform preorder, inorder, and postorder traversals.

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} treeNode;

treeNode* createNode(int value){
    //Allocate memory for a new Tree-Node
    treeNode* newNode = (treeNode*)malloc(sizeof(sizeof(treeNode)));

    if(newNode != NULL){
        newNode->data = value; // Initialize node data
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode; //Return created node
}

treeNode* insertNode(treeNode* root, int value){
    // If tree is empty, create new node
    if(root == NULL){
        return createNode(value);
    }

    // Create a queue for level-order traversal
    treeNode* queue[100]; // Array
    int front = 0, rear = 0;
    queue[rear++] = root;

    while(front<rear){
        treeNode* current = queue[front++];

        if(current->left==NULL){ // Left child slot empty
            current->left = createNode(value);
            break;
        } else {
            queue[rear++] = current->left;
        }
        if(current->right==NULL){ // Right child slot empty
            current->right = createNode(value);
            break;
        } else {
            queue[rear++] = current->right;
        }
    }
    return root;
}

void freeTree(treeNode* root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void inOrderTraversal(treeNode* root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(treeNode* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(treeNode* root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    treeNode* root = NULL;
    int nodeValue;
    char choice; // To ask user if they want to insert
                 // more nodes.
    do{
        printf("Input a value to insert into the binary tree:");
        scanf("%d", &nodeValue);

        root = insertNode(root, nodeValue);

        printf("Do you want to insert another node?(y/n): ");
        scanf(" %c", &choice); // Space to account for the '\n' in the input buffer.
    } while (choice == 'y' || choice == 'Y');

    printf("\nPre-order Traversal of the Binary Tree: ");
    preOrderTraversal(root);
    printf("\n");

    printf("\nIn-order Traversal of the Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    printf("\nPost-order Traversal of the Binary Tree: ");
    postOrderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}