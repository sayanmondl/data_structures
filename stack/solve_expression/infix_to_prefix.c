#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int is_operand(char c) {
    return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z');
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/' || op == '%') return 2;
    else return -1;
}

char *infix_to_postfix(char *infix) {
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
            while (!is_empty(&stk) && priority(top(&stk)) >= priority(infix[i])) {
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

char *reverse_str(char *exp) {
    int st = 0;
    int end = strlen(exp) - 1;
    while (st < end) {
        char temp = exp[st];
        exp[st] = exp[end];
        exp[end] = temp;
        st++;
        end--;
    }
    return exp;
}

char *infix_to_prefix(char *infix) {
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') { infix[i] = ')'; }
        if (infix[i] == ')') { infix[i] = '('; }
    }
    char *rev = reverse_str(infix);
    char *pos = infix_to_postfix(rev);
    char *prefix = reverse_str(pos);
}

int main() {
    char *infix = "abcdefg";

    char *new = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    printf("%s", new);
    return 0;
}