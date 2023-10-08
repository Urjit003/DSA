#include "stdio.h"
#include "stdlib.h"

int main() {
    int arr[100];
    int size, pos, element;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    a1:
    printf("Enter the position at which you want to insert the element: ");
    scanf("%d", &pos);

    if (pos > size || pos < 1) {
        printf("Invalid position!\n");
        goto a1;
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    for (int i = size - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = element;
    size++;

    printf("Updated array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}