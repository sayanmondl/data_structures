#include <stdio.h>

void printshifts(int n, char a, char b, char c) {
    if (n == 1) {
        printf("d%d: %c -> %c\n", n, a, c);
        return;
    }
    printshifts(n - 1, a, c, b);
    printf("d%d: %c -> %c\n", n, a, b);
    printshifts(n - 1, b, a, c);
}

int main() {
    printshifts(3, 'a', 'b', 'c');
    return 0;
}