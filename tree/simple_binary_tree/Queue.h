#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QNode {
    Node* n;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
} Queue;

QNode* createQNode(Node* Node);
Queue* createQueue();
int isEmpty(Queue* q);
void enqueue(Node* Node, Queue* q);
Node* dequeue(Queue* q);

#endif