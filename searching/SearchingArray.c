#include <stdio.h>

void search(int* arr, int el, int size);

int main() {
    int arr[] = { 1, 3, 5, 2, 7, 10, 4, 9 };
    search(arr, 10, 8);
    return 0;
}

void search(int* arr, int el, int size) {
    int* indexes;
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (el == arr[i]) {
            indexes[j] = i;
            j++;
        }
    }
    if (j == 0) {
        printf("Element not found!\n");
        return;
    }
    for (int i = 0; i < j; i++) {
        printf("Element found in %dth index", indexes[i]);
    }
}