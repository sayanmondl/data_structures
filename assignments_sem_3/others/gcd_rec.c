#include <stdio.h>
int calculate_gcd(int a, int b);
int gcdf(int n, int el);

int main() {
    int n, el;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter integers: ");
    scanf("%d", &el);

    int gcd = gcdf(n, el);
    printf("gcd = %d", gcd);
    return 0;
}

int gcdf(int n, int el) {
    if (n == 1) {
        return el;
    }
    int i;
    scanf("%d", &i);
    el = calculate_gcd(i, el);
    n = n - 1;
    gcdf(n, el);
}

int calculate_gcd(int a, int b) {
    if (b != 0) {
        return calculate_gcd(b, a % b);
    } else {
        return a;
    }
}