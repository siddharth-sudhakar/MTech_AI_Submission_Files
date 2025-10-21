#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int globalCounter = 0;

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

int countTraverse(struct Node* head){
    struct Node* current = head;
    int counter = 0;

    if(head == NULL){
        return 0;
    }

    if(head->next == NULL){
        return 1;
    }

    while(current != NULL){
        counter++;
        current = current->next;
    }

    return counter;
}

void deleteNode(struct Node* prev,struct Node* current){
    prev->next = current->next;
    free(current);
}

void traverseList(struct Node* head){
    struct Node* current = head;
    struct Node* prev = NULL;
    int seenVals[50] = {0};
    bool flag = 0;

    while(current!= NULL){
        // Check with the array, if found, remove, if not, add to the array.
        for(int i=0; i<globalCounter; i++){
            if(current->data == seenVals[i]){
                flag=1;
                deleteNode(prev, current);
                current = prev->next;
                break;
            }
        }

        if(flag==0){
            seenVals[globalCounter] = current->data;
            globalCounter++;
            prev = current;
            current = current->next;
        }
        flag=0;
    }
}

void printList(struct Node* node){
    while(node!=NULL){
        printf("%d -> ", node->data);
        node=node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    struct Node* head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(3);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(7);
    head->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next = newNode(9);

    
    int counter = countTraverse(head);
    if(counter == 0 || counter == 1){
        printf("Insufficient number of nodes.");
        return 0;
    }

    printf("List before deleting duplicates: ");
    printList(head);

    traverseList(head);

    printf("List after deleting duplicates: ");
    printList(head);

    freeList(head);

    return 0;
}