#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 50

typedef struct Stack {
    int stack[50];
    int top;
} Stack;

Stack createStack();
int isEmpty(Stack *stk);
int isFull(Stack *stk);
void push(Stack *stk, int data);
int pop(Stack *stk);
int peek(Stack *stk);
void display(Stack stk);

int main() {
    Stack stk = createStack();
    push(&stk, 3);
    push(&stk, 4);
    push(&stk, 5);
    push(&stk, 6);
    display(stk);
    pop(&stk);
    printf("peeked: %d", peek(&stk));
    printf("\n\n");
    display(stk);
}

Stack createStack() {
    Stack stk;
    stk.top = -1;
    return stk;
}

int isEmpty(Stack *stk) {
    return (stk->top == -1);
}

int isFull(Stack *stk) {
    return (stk->top == MAX_STACK_SIZE);
}

void push(Stack *stk, int data) {
    if (isFull(stk)) {
        printf("Stack Overflow!");
        return;
    }
    stk->top++;
    stk->stack[stk->top] = data;
}

int pop(Stack *stk) {
    if (isEmpty(stk)) {
        printf("Stack Empty!");
        return -1;
    }
    int popped = stk->stack[stk->top];
    stk->top--;
    return popped;
}

int peek(Stack *stk) {
    if (isEmpty(stk)) {
        printf("Stack Empty!");
        return -1;
    }
    return stk->stack[stk->top];
}

void display(Stack stk) {
    printf("Stack:\n");
    for (int i = stk.top; i >= 0; i--) {
        printf("%d\n", stk.stack[i]);
    }
    printf("\n");
}