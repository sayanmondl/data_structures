#include <stdio.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition1(int *arr, int p, int r)
{
	int pivot = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, r);
	return i + 1;
}

int partition2(int *arr, int p, int r)
{
	int pivot = arr[p];
	int i = p + 1;
	int j = r;

	while (1) {
		while (i <= r && arr[i] <= pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		if (i < j)
			swap(arr, i, j);
		else
			break;
	}

	swap(arr, p, j);
	return j;
}

void quick_sort(int *arr, int p, int r)
{
	if (p < r) {
		int q = partition2(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
	}
}

void print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int arr[8] = { 5, 2, 6, 8, 3, 10, 7, 1 };
	print_array(arr, 8);
	quick_sort(arr, 0, 7);
	print_array(arr, 8);
	return 0;
}
