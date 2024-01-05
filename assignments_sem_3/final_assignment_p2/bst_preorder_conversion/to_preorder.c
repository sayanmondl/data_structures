#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int x, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void print_preorder(int inorder[], int postorder[], int n) {
    int root_index = search(inorder, postorder[n - 1], n);

    printf("%d ", postorder[n - 1]);

    if (root_index != 0) {
        print_preorder(inorder, postorder, root_index);
    }

    if (root_index != n - 1) {
        print_preorder(inorder + root_index + 1, postorder + root_index, n - root_index - 1);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes inorder the tree: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    printf("Preorder traversal: ");
    print_preorder(inorder, postorder, n);

    return 0;
}
