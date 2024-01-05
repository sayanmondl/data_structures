#include <stdio.h>

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int si = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[si] > arr[j]) {
                int temp = arr[si];
                arr[si] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 6, 7, 8, 2, 1, 3, 10, 11 };
    selection_sort(arr, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}