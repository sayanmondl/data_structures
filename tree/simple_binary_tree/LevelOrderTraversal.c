#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int idx = -1;
Node* buildTree(int* data) {
    idx++;
    if (data[idx] == -1) {
        return NULL;
    }

    Node* newNode = createNode(data[idx]);
    newNode->left = buildTree(data);
    newNode->right = buildTree(data);

    return newNode;
}

void level_order(Node* root) {
    if (root == NULL) {
        return;
    }

    Queue* q = create_queue();
    enqueue(root, q);
    enqueue(NULL, q);

    while (!is_empty(q)) {
        Node* current = dequeue(q);
        if (current == NULL) {
            printf("\n");
            if (is_empty(q)) {
                break;
            } else {
                enqueue(NULL, q);
            }
        } else {
            printf("%d  ", current->data);
            if (current->left != NULL) {
                enqueue(current->left, q);
            }
            if (current->right != NULL) {
                enqueue(current->right, q);
            }
        }
    }
}

int main() {
    int data[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 }; //-1 stands for NULL value

    Node* root = buildTree(data);
    printf("root = %d\n\n", root->data);

    printf("Levelorder traversal:\n");
    level_order(root);

    return 0;
}