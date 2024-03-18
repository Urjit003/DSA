#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *MakeArry(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter for index %d \n", i + 1);
        scanf("%d", &arr[i]);
    }
    return arr;
}
void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d]", arr[i]);
    }
    printf("\n");
}
int Partiton_diff(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;

    do
    {
        if (arr[j] < pivot)
        {
            i ++;
            swap(&arr[j],&arr[i]);
        }
        j++;
    }while(j < high);
    swap(&arr[i+1],&arr[high]);
    return i +1 ;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot) // arr[i] < arr[low]
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}
void QuickSort(int *arr, int low, int high)
{
    int PartitionIndex;

    if (low < high)
    {
        PartitionIndex = partition(arr, low, high);
        QuickSort(arr, low, PartitionIndex - 1);
        QuickSort(arr, PartitionIndex + 1, high);
    }
}
int main()
{
    int arr[] = {12, 4, 1, 23, 4, 123, 44, 53};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ParIndex = Partiton_diff(arr, 0 , size-1);
    PrintArray(arr, size);
    QuickSort(arr,0, size -1 );
    PrintArray(arr, size);
    // free(arr);
    return 0;
}