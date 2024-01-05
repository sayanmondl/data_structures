#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

void heapify_up(Heap *heap, int index) {
    // Swapping the child with its parent until the parent is smaller than the child
    while (index > 0 && heap->arr[index] < heap->arr[PARENT_INDEX(index)]) {
        swap(&(heap->arr[index]), &(heap->arr[PARENT_INDEX(index)]));
        index = PARENT_INDEX(index);
    }
}

void heapify_down(Heap *heap, int index) {
    int smallest = index;

    int left_child = LEFT_CHILD_INDEX(index);
    int right_child = RIGHT_CHILD_INDEX(index);

    // Comparing with left child
    if (left_child < heap->size && heap->arr[smallest] > heap->arr[left_child]) {
        smallest = left_child;
    }
    // Comparing with right child
    if (right_child < heap->size && heap->arr[smallest] > heap->arr[right_child]) {
        smallest = right_child;
    }
    /* If the 'smallest' is not same as 'index', swap the element at 'smallest'
    and 'index' and continue heapify down */
    if (smallest != index) {
        swap(&(heap->arr[smallest]), &(heap->arr[index]));
        heapify_down(heap, smallest);
    }
    return;
}

// Inserts new element in the heap
void insert(Heap *heap, int data) {
    heap->size++;
    // Reallocating the memory for the new element
    heap->arr = (int *)realloc(heap->arr, heap->size * sizeof(int));

    // Adding 'data' at the end of the heap
    int index = heap->size - 1;
    heap->arr[index] = data;

    // Heapify up to maintain heap property
    heapify_up(heap, index);
}

// Deletes an element from heap
void delete(Heap *heap, int index) {
    // Empty condition
    if (is_empty(heap) || index < 0 || index >= heap->size) {
        printf("Invalid!");
        return;
    }
    // Swapping the element to be deleted with the last element of the heap
    swap(&(heap->arr[index]), &(heap->arr[heap->size - 1]));

    heap->size--;
    // Heapify down to maintain heap property
    heapify_down(heap, index);
}

int main() {
    int arr[11] = { 75, 45, 34, 29, 44, 31, 19, 3, 17, 25, 54 };
    Heap *heap = heapify(arr, 11);

    insert(heap, 12);
    insert(heap, 46);
    insert(heap, 16);
    insert(heap, 59);
    insert(heap, 5);
    insert(heap, 64);

    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");

    delete(heap, 7);
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
    return 0;
}