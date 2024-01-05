#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int is_operand(char c) {
    return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/' || op == '%') return 2;
    else return -1;
}

char *infixToPostfix(char *infix) {
    Stack stk = create_stack();
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (is_operand(infix[i])) {
            postfix[j] = infix[i];
            j++;
        } else if (infix[i] == '(') {
            push(&stk, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(&stk) && top(&stk) != '(') {
                postfix[j] = pop(&stk);
                j++;
            }
            pop(&stk);
        } else {
            while (!is_empty(&stk) && precedence(top(&stk)) >= precedence(infix[i])) {
                postfix[j] = pop(&stk);
                j++;
            }
            push(&stk, infix[i]);
        }
    }

    while (!is_empty(&stk)) {
        postfix[j] = pop(&stk);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int evaluatePostfix(char *postfix) {
    Stack stk = create_stack();

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (is_operand(postfix[i])) {
            push(&stk, postfix[i] - '0');
        } else {
            int operand2 = pop(&stk);
            int operand1 = pop(&stk);

            switch (postfix[i]) {
                case '+':
                    push(&stk, operand1 + operand2);
                    break;
                case '-':
                    push(&stk, operand1 - operand2);
                    break;
                case '*':
                    push(&stk, operand1 * operand2);
                    break;
                case '/':
                    push(&stk, operand1 / operand2);
                    break;
                case '%':
                    push(&stk, operand1 % operand2);
                    break;
                default:
                    printf("Invalid postfix expression!");
                    return -1;
            }
        }
    }

    return pop(&stk);
}

int main() {
    printf("Enter the infix expression: ");
    char infix[100];
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    char *postfix = infixToPostfix(infix);
    printf("The Postfix result is: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("The Evaluation Result is: %d\n", result);

    return 0;
}

