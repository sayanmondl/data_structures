#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "heap.h"

Heap *create_heap() {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->arr = NULL;
    heap->size = 0;
    return heap;
}

Heap *heapify(int data[], int size) {
    Heap *heap = create_heap();
    heap->arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        heap->arr[i] = data[i];
    }
    heap->size = size;
    /* Heapifying down from every intermidiate node, starting from the
    last intermidiate node*/
    for (int i = LAST_INTERMIDIATE_NODE_INDEX(size); i >= 0; i--) {
        heapify_down(heap, i);
    }
    return heap;
}

bool is_empty(Heap *heap) { return (heap->size == 0); }

int get_size(Heap *heap) { return heap->size; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}