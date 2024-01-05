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

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d  ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int data1[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

    Node* root1 = buildTree(data1);
    printf("root1 = %d\n", root1->data);

    int data2[] = { 3, 7, 4, 3, -1, 5, -1, -1, 3, -1, 10, -1, -1 };

    idx = -1;
    Node* root2 = buildTree(data2);
    printf("root2 = %d\n\n", root2->data);

    preorderTraversal(root1);
    printf("\n");
    preorderTraversal(root2);
}