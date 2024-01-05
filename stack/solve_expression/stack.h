#ifndef STACK_H
#define STACK_H
#define MAX_STACK_SIZE 50

typedef struct Stack {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

Stack create_stack();
int is_empty(Stack *stk);
int is_full(Stack *stk);
void push(Stack *stk, char data);
int pop(Stack *stk);
int top(Stack *stk);
void display(Stack stk);

#endif