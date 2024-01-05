#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Queue *createQueue() {
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

int isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(int data, Queue *q) {
    Node *newNode = createNode(data);
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!");
        return -1;
    }
    if (q->front == q->rear) {
        int temp = q->front->data;
        q->front = q->rear = NULL;
        return temp;
    }
    int temp = q->front->data;
    q->front = q->front->next;
    return temp;
}

void displayQueue(Queue *q) {
    Node *current = q->front;
    printf("[  ");
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    Queue *q1 = createQueue();
    enqueue(1, q1);
    enqueue(2, q1);
    displayQueue(q1);
    dequeue(q1);
    displayQueue(q1);

    Queue *q2 = createQueue();
    enqueue(3, q2);
    enqueue(4, q2);
    displayQueue(q2);

    return 0;
}