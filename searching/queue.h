#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "graph.h"

typedef struct {
	int items[MAX_VERTICES];
	int front, rear;
} queue;

void init_queue(queue *q);
bool is_empty(queue *q);
void enqueue(queue *q, int val);
int dequeue(queue *q);

#endif
