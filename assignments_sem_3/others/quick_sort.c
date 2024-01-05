#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int *arr, int i, int j);
void print_array(int *arr, int size);

int main() {
    int arr[] = { 6, 7, 9, 4, 1, 2, 10, 3, 8 };
    quick_sort(arr, 0, 8);
    print_array(arr, 9);
    return 0;
}

void quick_sort(int *arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot_index = partition(arr, low, high);
    quick_sort(arr, low, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, high);
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (pivot > arr[j]) {
            i++;
            swap(arr, i, j);
        }
    }
    i++;
    swap(arr, i, high);
    return i;
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}