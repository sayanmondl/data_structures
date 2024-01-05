#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int data);
Node *insert(Node *root, int data);
void inorder_traversal(Node *root);
int search(Node *root, int el);
Node *delete_node(Node *root, int el);

int main() {
    int n;
    Node *root = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int sequence[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    for (int i = 0; i < 10; i++) {
        root = insert(root, sequence[i]);
    }

    // inorder traversal
    inorder_traversal(root);
    printf("\n");

    int del;
    printf("Which element you want to delete: ");
    scanf("%d", &del);
    delete_node(root, del);
    printf("\n");

    // inorder traversal
    inorder_traversal(root);
}

Node *create_node(int data) {
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data >= root->data) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }
    return root;
}

void inorder_traversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d  ", root->data);
    inorder_traversal(root->right);
}

Node *delete_node(Node *root, int el) {
    if (root == NULL) {
        printf("Element not found!");
        return root;
    }

    // finding the element to be deleted
    if (el > root->data) {
        root->right = delete_node(root->right, el);
    } else if (el < root->data) {
        root->left = delete_node(root->left, el);
    } else {
        // case 1 (if there is 1 or 0 child nodes)
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // case 2 (if there is 2 child nodes)
        Node *inorderSucc = root->right;
        while (inorderSucc->left != NULL) {
            inorderSucc = inorderSucc->left;
        }
        root->data = inorderSucc->data;
        root->right = delete_node(root->right, inorderSucc->data);
    }
    return root;
}