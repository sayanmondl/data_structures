#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

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

int main() {
    int data[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 }; //-1 stands for NULL value

    Node* root = buildTree(data);
    printf("root = %d", root->data);
}