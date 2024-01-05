#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

QNode* createQNode(Node* node) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->n = node;
    newNode->next = NULL;

    return newNode;
}

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

int isEmpty(Queue* q) {
    return (q->front == NULL) && (q->rear == NULL);
}

void enqueue(Node* node, Queue* q) {
    QNode* newNode = createQNode(node);
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!");
        return NULL;
    }
    if (q->front == q->rear) {
        Node* temp = q->front->n;
        q->front = q->rear = NULL;
        return temp;
    }
    Node* temp = q->front->n;
    q->front = q->front->next;
    return temp;
}