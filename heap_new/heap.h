#define PARENT(i) (i - 1) / 2
#define LEFT_CHILD(i) 2 * i + 1
#define RIGHT_CHILD(i) 2 * i + 2
#define LAST_INTERMIDIATE_NODE(size) (size - 2) / 2

typedef struct heap {
	int *arr;
	int size;
} heap;

/**
 * @param i First index
 * @param j Second index
 * @brief Swaps element at index `i` and `j`
 */
void swap(int *i, int *j);

/**
 * @param h The heap structure contains an array and size of the arr
 * @param i The index to start heapufying
 * @brief Performs max-heapify from the given index `i`
 */
void max_heapify(heap *h, int i);

/**
 * @param h Input unorderd heap
 * @brief Build the max-heap from a unordered array
 */
void build_max_heap(heap *h);

/**
 * @param h Input unorderd heap
 * @brief Sorts the array
 */
void heap_sort(heap *h);

/**
 * @param h The heap
 * @brief Prints the array
 */
void print_array(heap * h);