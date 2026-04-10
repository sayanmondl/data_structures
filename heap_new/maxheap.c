#include <stdio.h>
#include "heap.h"

int main()
{
	int arr[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	heap h;
	h.arr = arr;
	h.size = size;

	printf("Before sorting:\n");
	print_array(&h);

	heap_sort(&h);

	printf("After sorting:\n");
	print_array(&h);

	return 0;
}