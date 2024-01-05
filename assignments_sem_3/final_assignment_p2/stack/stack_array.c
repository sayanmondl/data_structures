#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct Stack {
    int stack[50];
    int top;
} Stack;

Stack createStack();
int isEmpty(Stack *stk);
int isFull(Stack *stk);
void push(Stack *stk, int data);
int pop(Stack *stk);
void display(Stack stk);

int main() {
    Stack stk = createStack();

    push(&stk, 3);
    push(&stk, 9);
    push(&stk, 1);
    push(&stk, 6);
    push(&stk, 17);
    display(stk);

    pop(&stk);
    pop(&stk);
    display(stk);

    push(&stk, 45);
    display(stk);

    return 0;
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

void display(Stack stk) {
    printf("Stack:\n");
    for (int i = stk.top; i >= 0; i--) {
        printf("%d\n", stk.stack[i]);
    }
    printf("\n");
}