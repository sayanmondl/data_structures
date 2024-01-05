#include <stdio.h>

void insertionSort(int* arr, int size) {
    for (int usi = 1; usi < size; usi++) {
        int key = arr[usi];
        int sli = usi - 1;
        while (sli >= 0 && key < arr[sli]) {
            arr[sli + 1] = arr[sli];
            sli--;
        }
        arr[sli + 1] = key;
    }
}

int main() {
    int arr[] = { 6, 7, 8, 2, 1, 3, 10, 11 };
    insertionSort(arr, 8);
    for (int i = 0; i < 8; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}