#include <stdio.h>
int main() {
    int element, small;
    int n;
    printf("Enter the number of integers to be added : ");
    scanf("%d", &n);
    printf("Enter integers: \n");
    scanf("%d", &small);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &element);
        if (element < small) {
            small = element;
        }
    }
    printf("smallest = %d", small);
    return 0;
}