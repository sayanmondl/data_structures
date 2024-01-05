#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

//using array
typedef struct DEqueue {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} DEqueue;

DEqueue create_DEqueue();
int is_empty(DEqueue *deque);
int is_full(DEqueue *deque);
void push_back(DEqueue *deque, int data);
void push_front(DEqueue *deque, int data);
void pop_back(DEqueue *deque);
void pop_front(DEqueue *deque);
int front(DEqueue *deque);
int back(DEqueue *deque);
void display(DEqueue *deque);

int main() {
    //creation
    DEqueue deque = create_DEqueue();

    //insertions
    push_back(&deque, 7);
    push_front(&deque, 9);
    push_back(&deque, 5);
    push_front(&deque, 1);
    push_back(&deque, 12);
    push_front(&deque, 13);
    push_back(&deque, 11);
    push_front(&deque, 6);

    //display
    printf("Deque: ");
    display(&deque);

    //deletions and changes
    pop_back(&deque);
    pop_back(&deque);
    pop_front(&deque);
    push_back(&deque, 17);
    printf("Deque: ");
    display(&deque);
    printf("\n");

    //fetching
    printf("front: %d\t", front(&deque));
    printf("rear: %d\n\n", back(&deque));
    printf("Deque: ");
    display(&deque);
}

DEqueue create_DEqueue() {
    DEqueue deque;
    deque.front = -1;
    deque.rear = -1;
    return deque;
}

int is_empty(DEqueue *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int is_full(DEqueue *deque) {
    return ((deque->rear + 1) % MAX_QUEUE_SIZE == deque->front);
}

// function to insert an element at the rear of the deque
void push_back(DEqueue *deque, int data) {
    //overflow condition
    if (is_full(deque)) {
        printf("Queue full! Element can't be inserted");
    } else {
        //empty condition
        if (is_empty(deque)) {
            deque->front = 0;
            deque->rear = 0;
        } else {
            deque->rear = (deque->rear + 1) % MAX_QUEUE_SIZE;
        }
        deque->queue[deque->rear] = data;
    }
}

// function to insert an element at the front of the deque
void push_front(DEqueue *deque, int data) {
    //overflow condition
    if (is_full(deque)) {
        printf("Queue full! Element can't be inserted.");
    } else {
        //empty condition
        if (is_empty(deque)) {
            deque->front = 0;
            deque->rear = 0;
        } else {
            deque->front = (deque->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
        deque->queue[deque->front] = data;
    }
}

//function to delete an element from the rear of the deque
void pop_back(DEqueue *deque) {
    //empty condition
    if (is_empty(deque)) {
        printf("Queue is empty! Element can't be deleted.");
    } else {
        //one element condition
        if (deque->front == deque->rear) {
            deque->front = -1;
            deque->rear = -1;
        } else {
            deque->rear = deque->rear - 1;
            if (deque->rear < 0) {
                deque->rear = MAX_QUEUE_SIZE - 1;
            }
        }
    }
}

//function to delete an element from the front of the deque
void pop_front(DEqueue *deque) {
    //empty condition
    if (is_empty(deque)) {
        printf("Queue is empty! Element can't be deleted.");
    } else {
        //one element condition
        if (deque->front == deque->rear) {
            deque->front = -1;
            deque->rear = -1;
        } else {
            deque->front = (deque->front + 1) % MAX_QUEUE_SIZE;
        }
    }
}

//function to get the front element of the deque
int front(DEqueue *deque) {
    return deque->queue[deque->front];
}

//function to get the rear element od the deque
int back(DEqueue *deque) {
    return deque->queue[deque->rear];
}

void display(DEqueue *deque) {
    //empty condition
    if (is_empty(deque)) {
        printf("Queue is empty!");
        return;
    }
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d\t", deque->queue[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", deque->queue[deque->rear]);
}