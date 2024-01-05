#include <stdio.h>
int calculate_gcd(int a, int b);
int calculate_lcm(int a, int b);
int lcmf(int n, int el);

int main() {
    int n, el;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter integers: ");
    scanf("%d", &el);

    int lcm = lcmf(n, el);
    printf("lcm = %d", lcm);
    return 0;
}

int lcmf(int n, int el) {
    if (n == 1) {
        return el;
    }
    int i;
    scanf("%d", &i);
    el = calculate_lcm(i, el);
    n = n - 1;
    lcmf(n, el);
}

int calculate_lcm(int a, int b) {
    return (a * b) / calculate_gcd(a, b);
}

int calculate_gcd(int a, int b) {
    if (b != 0) {
        return calculate_gcd(b, a % b);
    } else {
        return a;
    }
}