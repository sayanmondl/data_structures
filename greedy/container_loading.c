#include <stdio.h>

#define NUMBER_OF_CONTAINERS 10

typedef struct container {
	int id;
	int weight;
} container;

void swap(container *c, int i, int j)
{
	container temp = c[i];
	c[i] = c[j];
	c[j] = temp;
}

void sort(container *c, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (c[j].weight > c[j + 1].weight) {
				swap(c, j, j + 1);
			}
		}
	}
}

void container_loading(container *c, int capacity, int number_of_containers,
		       int *x)
{
	sort(c, number_of_containers);
	int n = number_of_containers;

	int i;
	for (i = 0; i < n; i++) {
		x[i] = 0;
	}
	i = 0;

	while (i < n && c[i].weight <= capacity) {
		x[c[i].id] = 1;
		capacity = capacity - c[i].weight;
        i++;
	}
}

int main(int argc, char const *argv[])
{
	container c[NUMBER_OF_CONTAINERS] = {
		{ 0, 10 }, { 1, 3 },  { 2, 4 },	 { 3, 1 }, { 4, 7 },
		{ 5, 11 }, { 6, 15 }, { 7, 12 }, { 8, 5 }, { 9, 2 }
	};

	int x[NUMBER_OF_CONTAINERS];
	int capacity = 50;
	container_loading(c, capacity, NUMBER_OF_CONTAINERS, x);

	for (int i = 0; i < NUMBER_OF_CONTAINERS; i++) {
		printf("%d", x[i]);
	}

	return 0;
}
