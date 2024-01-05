#ifndef BINARY_SEARCH_TREE 
#define BINARY_SEARCH_TREE

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

#endif