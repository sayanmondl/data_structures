#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "graph.h"

typedef struct {
	int items[MAX_VERTICES];
	int top;
} stack;

void init_stack(stack *s);
bool is_stack_empty(stack *s);
void push(stack *s, int val);
int pop(stack *s);
int peek(stack *s);

#endif