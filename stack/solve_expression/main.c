#include <stdio.h>
#include <stdlib.h>
#include "expressions.h"

int main() {
    char *infix = "1+2-3*4";
    char *post = infix_to_postfix(infix);
    char *pre = infix_to_prefix(infix);

    printf("The Postfix result is:%s\n", post);
    printf("The Prefix result is:%s\n", pre);

    printf("Fnal answer: %d", evaluate_postfix(post));

    free(post);
    free(pre);
    return 0;
}