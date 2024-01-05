#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Heapify down implementation for max-heap
void heapify_down_max(Heap *heap, int index) {
    int largest = index;

    int left_child = LEFT_CHILD_INDEX(index);
    int right_child = RIGHT_CHILD_INDEX(index);

    // Comparing with left child
    if (left_child < heap->size && heap->arr[largest] < heap->arr[left_child]) {
        largest = left_child;
    }
    // Comparing with right child
    if (right_child < heap->size && heap->arr[largest] < heap->arr[right_child]) {
        largest = right_child;
    }
    /* If the 'largest' is not same as 'index', swap the element at 'largest'
    and 'index' and continue heapify down */
    if (largest != index) {
        swap(&(heap->arr[largest]), &(heap->arr[index]));
        heapify_down_max(heap, largest);
    }
    return;
}

// Heapify down implementation for min-heap
void heapify_down_min(Heap *heap, int index) {
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
        heapify_down_min(heap, smallest);
    }
    return;
}

// Implementing Heap sort (ascending) using max_heap
void heap_sort_ascending(Heap *heap) {
    // Creating new array to store sorted array and allocating memory
    int *new_arr = (int *)malloc(heap->size * sizeof(int));

    int old_size = heap->size;
    int last_index = heap->size - 1;

    for (last_index; last_index >= 0; last_index--) {
        // Swapping the last element and the first element(root)
        swap(&(heap->arr[0]), &(heap->arr[last_index]));

        // Assigning the largest element at last index of the newly created array
        new_arr[last_index] = heap->arr[last_index];

        // reducing the heap size
        heap->size--;

        heapify_down_max(heap, 0);
    }
    // Set the size as previous
    heap->size = old_size;

    // Now put the new_arr to the heap->arr
    heap->arr = new_arr;

    free(new_arr);
}

// Implementing Heap sort (descending) using min_heap
void heap_sort_descending(Heap *heap) {
    // Creating new array to store sorted array and allocating memory
    int *new_arr = (int *)malloc(heap->size * sizeof(int));

    int old_size = heap->size;
    int last_index = heap->size - 1;

    for (last_index; last_index >= 0; last_index--) {
        // Swapping the last element and the first element(root)
        swap(&(heap->arr[0]), &(heap->arr[last_index]));

        // Assigning the largest element at last index of the newly created array
        new_arr[last_index] = heap->arr[last_index];

        // reducing the heap size
        heap->size--;

        heapify_down_min(heap, 0);
    }
    // Set the size as previous
    heap->size = old_size;

    // Now put the new_arr to the heap->arr
    heap->arr = new_arr;

    free(new_arr);
}