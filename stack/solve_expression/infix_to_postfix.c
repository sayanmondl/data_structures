#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

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

int main() {
    char *infix = "a+b-(c*d)*e+f-g";
    printf("The Postfix result is:%s", infixToPostfix(infix));
    return 0;
}