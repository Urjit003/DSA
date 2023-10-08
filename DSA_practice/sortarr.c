#include <stdio.h>
#include <stdlib.h>
void Swap(int *a, int *b);
void Traverse(int *arr, int size);
void SortArray(int *arr, int size);

void Swap(int *a, int *b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}
void Traverse(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
void SortArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}
int main()
{
    int arr[] = {1, 2, 32, 5, 53, 4, 41, 4, 23, 55};
    int size = sizeof(arr) / sizeof(int);
    Traverse(arr, size);
    SortArray(arr, size);
    Traverse(arr, size);
    return 0;
}