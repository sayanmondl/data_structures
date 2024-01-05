#include <stdio.h>
int main() {
    int element, large, small;
    int n;
    printf("Enter the number of integers to be added : ");
    scanf("%d", &n);
    printf("Enter integers: \n");
    scanf("%d", &small);
    large = small;

    for (int i = 2; i <= n; i++) {
        scanf("%d", &element);
        if (element > large) {
            large = element;
        }
        if (element < small) {
            small = element;
        }
    }

    printf("largest = %d\n", large);
    printf("Smallest = %d", small);
    return 0;
}