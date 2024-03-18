#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
void ArraySort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {10, 15, 20, 2, 12, 2, 44, 21, 33};
    int size = sizeof(arr) / sizeof(int);
    ArraySort(arr, size);
    PrintArray(arr, size);
    return 0;
}