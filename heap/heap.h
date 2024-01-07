#include <stdbool.h>

#define PARENT_INDEX(i) (i - 1) / 2
#define LEFT_CHILD_INDEX(i) 2 * i + 1
#define RIGHT_CHILD_INDEX(i) 2 * i + 2
#define LAST_INTERMIDIATE_NODE_INDEX(size) (size - 2 ) / 2

typedef struct Heap {
    int *arr;
    int size;
} Heap;

// Creates an empty heap
Heap *create_heap();

// Utils
bool is_empty(Heap *heap);
int get_size(Heap *heap);
void display_heap(Heap *heap);
void swap(int *a, int *b);

// Inserts an element in the heap
void insert(Heap *heap, int data);

// Deletes an element from the heap
void delete(Heap *heap, int index);

// Builds heap(max or min, based on function implementation) from array of data
Heap *heapify(int data[], int size);

/* Implementation of heapify up and heapify down for max heap and
min heap are different */
// Function to heapify up (Used after insertion)
void heapify_up(Heap *heap, int index);

// Function to heapify down (Used after deletion)
void heapify_down(Heap *heap, int index);

//Sortings
void heap_sort_ascending(Heap *heap);
void heap_sort_descending(Heap *heap);