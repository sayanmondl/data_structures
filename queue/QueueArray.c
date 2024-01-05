#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef struct Queue {
    int queue[MAX_QUEUE_SIZE];
    int rear;
} Queue;

Queue createQueue();
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int getElement(Queue *q, int position);
void display(Queue q);

int main() {
    Queue q = createQueue();
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    display(q);
    dequeue(&q);
    printf("%d", getElement(&q, 2));
    printf("\n");
    display(q);
}

Queue createQueue() {
    Queue q;
    q.rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    return (q->rear == -1);
}

int isFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE);
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue full!");
        return;
    }
    q->rear++;
    q->queue[q->rear] = data;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue empty!");
        return -1;
    }
    if (q->rear == 0) {
        q->rear = -1;
        return q->queue[0];
    }
    int front = q->queue[0];
    for (int i = 0; i < q->rear; i++) {
        q->queue[i] = q->queue[i + 1];
    }
    q->rear--;
    return front;
}

int getElement(Queue *q, int position) {
    return q->queue[position - 1];
}

void display(Queue q) {
    for (int i = 0; i <= q.rear; i++) {
        printf("%d\t", q.queue[i]);
    }
    printf("\n");
}