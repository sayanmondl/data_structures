#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack create_stack() {
    Stack stk;
    stk.top = -1;
    return stk;
}

int is_empty(Stack *stk) {
    return (stk->top == -1);
}

int is_full(Stack *stk) {
    return (stk->top == MAX_STACK_SIZE);
}

void push(Stack *stk, char data) {
    if (is_full(stk)) {
        printf("Stack Overflow!");
        return;
    }
    stk->top++;
    stk->stack[stk->top] = data;
}

int pop(Stack *stk) {
    if (is_empty(stk)) {
        printf("Stack Empty!");
        return -1;
    }
    int popped = stk->stack[stk->top];
    stk->top--;
    return popped;
}

int top(Stack *stk) {
    if (is_empty(stk)) {
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