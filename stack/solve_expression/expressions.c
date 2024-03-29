#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "expressions.h"

int is_operand(char c) {
    return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/' || op == '%') return 2;
    else return -1;
}

char *infix_to_postfix(char *infix) {
    Stack stk = create_stack();
    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (is_operand(infix[i])) {
            prefix[j] = infix[i];
            j++;
        } else if (infix[i] == '(') {
            push(&stk, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(&stk) && top(&stk) != '(') {
                prefix[j] = pop(&stk);
                j++;
            }
            pop(&stk);
        } else {
            while (!is_empty(&stk) && precedence(top(&stk)) >= precedence(infix[i])) {
                prefix[j] = pop(&stk);
                j++;
            }
            push(&stk, infix[i]);
        }
    }

    while (!is_empty(&stk)) {
        prefix[j] = pop(&stk);
        j++;
    }
    prefix[j] = '\0';
    return prefix;
}

char *reverse_str(char *exp) {
    int len = strlen(exp);
    char *reversed = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        reversed[i] = exp[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

char *infix_to_prefix(char *infix) {
    char *rev = reverse_str(infix);
    int len = strlen(rev);
    for (int i = 0; i < len; i++) {
        if (rev[i] == '(') {
            rev[i] = ')';
        } else if (rev[i] == ')') {
            rev[i] = '(';
        }
    }
    char *post = infix_to_postfix(rev);
    char *prefix = reverse_str(post);

    free(rev);
    free(post);
    return prefix;
}

int evaluate_postfix(char *prefix) {
    Stack stk = create_stack();

    for (int i = 0; prefix[i] != '\0'; i++) {
        if (is_operand(prefix[i])) {
            push(&stk, prefix[i] - 48);
        } else {
            char operator = prefix[i];
            int operand1 = pop(&stk);
            int operand2 = pop(&stk);

            switch (operator) {
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
                default:
                    printf("Invalid!");
                    break;
            }
        }
    }
    return pop(&stk);
}

int evaluate_prefix(char *prefix) {
    Stack stk = create_stack();
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        if (is_operand(prefix[i])) {
            push(&stk, prefix[i] - 48);
        } else {
            char operator = prefix[i];
            int operand1 = pop(&stk);
            int operand2 = pop(&stk);

            switch (operator) {
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
                default:
                    printf("Invalid!");
                    break;
            }
        }
    }
    return pop(&stk);
}
