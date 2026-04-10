#include <stdbool.h>
#include "graph.h"
#include "queue.h"

void init_queue(queue *q)
{
	q->front = q->rear = -1;
}

bool is_empty(queue *q)
{
	return q->front == -1;
}

void enqueue(queue *q, int val)
{
	if (q->rear == MAX_VERTICES - 1)
		return;
	if (is_empty(q))
		q->front = 0;
	q->items[++q->rear] = val;
}

int dequeue(queue *q)
{
	int val = q->items[q->front];
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front++;
	return val;
}
