CC = gcc
CFLAGS = -Wall -g
DIR = build

all: maxheap minheap

maxheap: $(DIR)/heap.o $(DIR)/max_heap.o $(DIR)/heap_sort.o
	$(CC) $(CFLAGS) $^ -o maxheap

minheap: $(DIR)/heap.o $(DIR)/min_heap.o $(DIR)/heap_sort.o
	$(CC) $(CFLAGS) $^ -o minheap

$(DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(DIR)/*.o maxheap minheap
