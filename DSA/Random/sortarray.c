#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printarray(int *arr, int size)
{
    // int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        printf("%d[%d]\n", arr[i], i);
    }
}
void swap (int *a , int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp ;

}
void sortarray(int arr[], int size)
{
    // ascending order
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] >arr [j])
            {
               swap(&arr[i],&arr[j]);
            }
        }
    }
}
void sortarray_d(int arr[], int size)
{
    // dec order
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {68,123,5434,5345,45,9};
    int size = sizeof(arr) / sizeof(int);
    printarray(arr, size);
    sortarray(arr, size);
    printf("After sorting\n");
    printarray(arr, size);
    return 0;
}