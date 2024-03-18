#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *makearry(int size)
{
    int newsize;
    do
    {
        printf("Enter a positive integer \n");
        scanf("%d", &newsize);

        if (newsize <= 0)
        {
            printf("Invalid Input please try again (positive integers only)\n");
        }

    } while (newsize <= 0);
    size = newsize;
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        printf("Enter element for %d :\n", i + 1);
        scanf("%d", &arr[i]);
    }
    return arr;
}
int sortarray(int arr[], int size)
{
    int IsSorted = 0;
    // ascending order
    for (int i = 0; i < size; i++)
    {
        IsSorted = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                IsSorted = 0;
            }
        }
        if(IsSorted) {
            break;
        }
    }
    return 1;
}
void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
void BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Doing %d%s iteration\n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                  : (i + 1 == 3)   ? "rd"
                                                                                   : "th");
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // int temp = arr[j] ;
                // arr[j] = arr[j+1];
                // arr[j+1]=temp;
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void BubbleSort_Adaptive(int *arr, int n)
{
    int swapped = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Doing %d%s iteration\n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                  : (i + 1 == 3)   ? "rd"
                                                                                   : "th");

        swapped = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 0;
            }
        }
        if (swapped)
        {
            return;
        }
    }
}
int main()
{
    // int arr[] = {10, 20, 3, 1, 23, 33, 4123};
    int size;
    printf("Enter the size of your array \n");
    scanf("%d", &size);
    int *arr = makearry(size);
    PrintArray(arr, size);
    BubbleSort_Adaptive(arr, size);
    PrintArray(arr, size);
    return 0;
}