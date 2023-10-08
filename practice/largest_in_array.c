#include <stdio.h>
#include <stdlib.h>
int largest(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
int main()
{
    int arr[] = {1, 2, 543, 123, 54235, 5234, 2342, 34, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", largest(arr, size));
    return 0;
    printf(12>12);
}