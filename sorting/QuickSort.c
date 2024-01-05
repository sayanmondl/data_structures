#include <stdio.h>

void quickSort(int* arr, int low, int high) {

}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    return 0;
}