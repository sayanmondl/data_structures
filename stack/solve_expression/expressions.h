#ifndef EXPRESSION_H
#define EXPRESSION_H

int is_operand(char c);
int precedence(char op);
char *reverse_str(char *exp);
char *infix_to_postfix(char *infix);
char *infix_to_prefix(char *infix);
int evaluate_postfix(char *postfix);
int evaluate_prefix(char *prefix);

#endif