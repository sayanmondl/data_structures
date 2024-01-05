#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Deque {
    Node *front;
    Node *rear;
} Deque;

Node *create_Node(int data);
Deque *create_Deque();
int is_empty(Deque *deque);
void push_back(Deque *deque, int data);
void push_front(Deque *deque, int data);
void pop_back(Deque *deque);
void pop_front(Deque *deque);
int front(Deque *deque);
int back(Deque *deque);
void display(Deque *deque);

int main() {
    //creation
    Deque *deque = create_Deque();

    //insertions
    push_back(deque, 7);
    push_front(deque, 9);
    push_back(deque, 5);
    push_front(deque, 1);
    push_back(deque, 12);
    push_front(deque, 13);
    push_back(deque, 11);
    push_front(deque, 6);

    //display
    printf("Deque: ");
    display(deque);

    //deletions and changes
    pop_back(deque);
    pop_back(deque);
    pop_front(deque);
    push_back(deque, 17);
    printf("Deque: ");
    display(deque);
    printf("\n");

    //fetching
    printf("front: %d\t", front(deque));
    printf("rear: %d\n\n", back(deque));
    printf("Deque: ");
    display(deque);
}

Node *create_Node(int data) {
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Deque *create_Deque() {
    Deque *deque = (Deque *)calloc(1, sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int is_empty(Deque *deque) {
    return (deque->front == NULL);
}

// function to insert an element at the rear of the deque
void push_back(Deque *deque, int data) {
    Node *newNode = create_Node(data);
    if (is_empty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// function to insert an element at the front of the deque
void push_front(Deque *deque, int data) {
    Node *newNode = create_Node(data);
    if (is_empty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

//function to delete an element from the rear of the deque
void pop_back(Deque *deque) {
    if (is_empty(deque)) {
        printf("Queue is empty! Nothing to delete.");
    } else {
        Node *current = deque->front;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = NULL;
        deque->rear = current;
        free(temp);
    }
}

//function to delete an element from the front of the deque
void pop_front(Deque *deque) {
    if (is_empty(deque)) {
        printf("Queue is empty! Nothing to delete.");
    } else {
        Node *temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
}

//function to get the front element of the deque
int front(Deque *deque) {
    return deque->front->data;
}

//function to get the rear element od the deque
int back(Deque *deque) {
    return deque->rear->data;
}

void display(Deque *deque) {
    if (is_empty(deque)) {
        printf("Queue is empty!");
        return;
    }
    Node *current = deque->front;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}