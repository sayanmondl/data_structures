#include <stdio.h>
int main() {
    int element, large;
    int n;
    printf("Enter the number of integers to be added : ");
    scanf("%d", &n);
    printf("Enter integers: \n");
    scanf("%d", &large);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &element);
        if (element > large) {
            large = element;
        }
    }
    printf("largest = %d", large);
    return 0;
}