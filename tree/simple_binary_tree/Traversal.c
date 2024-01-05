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

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

int main() {
    int data[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 }; //-1 stands for NULL value

    Node* root = buildTree(data);
    printf("root = %d\n\n", root->data);

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n\n");

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n\n");

    return 0;
}