#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int x, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void print_postorder(int inorder[], int preorder[], int n) {
    int root_index = search(inorder, preorder[0], n);

    if (root_index != 0) {
        print_postorder(inorder, preorder + 1, root_index);
    }
    if (root_index != n - 1) {
        print_postorder(inorder + root_index + 1, preorder + root_index + 1, n - root_index - 1);
    }
    printf("%d ", preorder[0]);
}

int main() {
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    int in[n], pre[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    printf("Postorder traversal: ");
    print_postorder(in, pre, n);
}
