#include <stdio.h>
#include <stdlib.h>
#define LOAD_FACTOR 0.75
#define INITIAL_CAPACITY 10

typedef struct Node {
    void *key;
    void *value;
    struct Node *next;
} Node;

typedef struct HashMap {
    Node **buckets;
    int capacity;
    int size;
} HashMap;

HashMap *initHashMap();
unsigned int hash(void *key, int capacity);
void insert(HashMap **map, void *key, void *value);
void rehash(HashMap **map);
void *get(HashMap *map, void *key);

int main() {
    HashMap *map = initHashMap();

    // key - value pair 1
    int key1 = 42;
    int value1 = 100;
    insert(&map, &key1, &value1);

    // key - value pair 2
    char key2[] = "hello";
    char value2[] = "world";
    insert(&map, key2, value2);

    // retrieving
    int *result1 = (int *)get(map, &key1);
    if (result1 != NULL) {
        printf("Value for key1: %d\n", *result1);
    } else {
        printf("Key1 not found\n");
    }

    char *result2 = (char *)get(map, key2);
    if (result2 != NULL) {
        printf("Value for key2: %s\n", result2);
    } else {
        printf("Key2 not found\n");
    }
    return 0;
}

HashMap *initHashMap() {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->capacity = INITIAL_CAPACITY;
    map->size = 0;
    map->buckets = (Node **)calloc(map->capacity, sizeof(Node *));
    for (int i = 0; i < map->capacity; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

// hash function
unsigned int hash(void *key, int capacity) {
    char *str = (char *)key;
    unsigned int hash = 5389;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % capacity;
}

void insert(HashMap **map, void *key, void *value) {
    // checking if load factor exceeds
    if ((double)(*map)->size / (*map)->capacity > LOAD_FACTOR) {
        // rehash
        rehash(map);
    }

    // getting index
    unsigned int index = hash(key, (*map)->capacity);

    // creating node
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if ((*map)->buckets[index] == NULL) {
        // If the bucket is empty, set the new node as the head
        (*map)->buckets[index] = new_node;
    } else {
        // Otherwise, append the new node to the end of the linked list
        Node *current = (*map)->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    (*map)->size++;
}


void *get(HashMap *map, void *key) {
    unsigned int index = hash(key, map->capacity);
    Node *current = map->buckets[index];
    while (current->key != key) {
        current = current->next;
    }
    if (current->key == key) {
        return current->value;
    }
    return NULL;
}

void rehash(HashMap **map) {
    // doubling the size
    int new_capacity = 2 * (*map)->capacity;
    // creating new array of Node pointers & allocating memory
    Node **new_buckets = (Node **)calloc(new_capacity, sizeof(Node *));
    for (int i = 0; i < new_capacity; i++) {
        new_buckets[i] = NULL;
    }
    // putting all nodes to the new_buckets
    for (int i = 0; i < (*map)->capacity; i++) {
        Node *current = (*map)->buckets[i];
        while (current != NULL) {
            unsigned int new_index = hash(current->key, new_capacity);
            new_buckets[new_index] = current;
            current = current->next;
        }
    }
    free((*map)->buckets);
    (*map)->buckets = new_buckets;
    (*map)->capacity = new_capacity;
}