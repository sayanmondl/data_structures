#include <stdio.h>
#include "stack.h"

void init_stack(stack *s)
{
	s->top = -1;
}

bool is_stack_empty(stack *s)
{
	return s->top == -1;
}

void push(stack *s, int val)
{
	if (s->top == MAX_VERTICES - 1) {
		printf("Stack overflow\n");
		return;
	}

	s->items[++s->top] = val;
}

int pop(stack *s)
{
	if (is_stack_empty(s)) {
		printf("Stack underflow\n");
		return -1;
	}

	return s->items[s->top--];
}

int peek(stack *s)
{
	if (is_stack_empty(s)) {
		printf("Stack is empty\n");
		return -1;
	}

	return s->items[s->top];
}