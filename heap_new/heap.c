#include <stdio.h>
#include "heap.h"

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void max_heapify(heap *h, int i)
{
	int l = LEFT_CHILD(i);
	int r = RIGHT_CHILD(i);
	int largest;

	if (l < h->size && h->arr[l] > h->arr[i])
		largest = l;
	else
		largest = i;

	if (r < h->size && h->arr[r] > h->arr[largest])
		largest = r;

	if (largest != i) {
		swap(&(h->arr[largest]), &(h->arr[i]));
		max_heapify(h, largest);
	}
}

void build_max_heap(heap *h)
{
	for (int i = LAST_INTERMIDIATE_NODE(h->size); i >= 0; i--) {
		max_heapify(h, i);
	}
}

void heap_sort(heap *h)
{
	int original_size = h->size;
	build_max_heap(h);

	for (int i = h->size - 1; i > 0; i--) {
		swap(&h->arr[0], &h->arr[i]);
		h->size--;
		max_heapify(h, 0);
	}
	h->size = original_size;
}

void print_array(heap *h)
{
	for (int i = 0; i < h->size; i++) {
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}