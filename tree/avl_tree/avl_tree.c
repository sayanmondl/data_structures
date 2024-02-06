#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node *create_node(int data);
Node *insert(Node *root, int data);
void inorder_traversal(Node *root);
int search(Node *root, int el);
Node *delete(Node *root, int el);

int main() {
}

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
}

void inorder_traversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d  ", root->data);
    inorder_traversal(root->right);
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        Node *new_node = create_node(data);

    }
    if (data >= root->data) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }
}