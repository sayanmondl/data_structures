#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Node* head = NULL;

void push(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

int pop() {
    if (head == NULL) {
        printf("Empty Stack");
        return -1;
    }

    int temp = head->data;
    head = head->next;
    return temp;
}

int peek(int position) {
    if (head == NULL) {
        printf("Empty Stack");
        return -1;
    }

    if (position == 1) {
        return head->data;
    }

    Node* current = head;
    for (int i = 2; i <= position; i++) {
        if (current->next == NULL) {
            printf("Position exceeds stack size\n");
            return -1;
        }
        current = current->next;
    }
    return current->data;
}

void displayStack() {
    Node* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(7);
    push(6);
    push(5);
    push(4);
    push(3);
    push(2);    
    push(1);
    displayStack();

    int pop_value = pop();
    if (pop_value != -1) {
        printf("Popped: %d\n", pop_value);
    }
    displayStack();

    int peek_value = peek(3);
    if (peek_value != -1) {
        printf("Peeked: %d\n", peek_value);
    }
    return 0;
}