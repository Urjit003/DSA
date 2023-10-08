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
void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}
void InsertionSort(int *arr, int size)
{
    int key;
    // loop for passes
    for (int i = 0; i < size; i++)
    {
        printf("Doing %d%s iteration\n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                  : (i + 1 == 3)   ? "rd"
                                                                                   : "th");
        key = arr[i];
        int j = i - 1;
        // loop for each pass
        while (j >= 0 && arr[j] > key)
        {
            // arr[j + 1] = arr[j];
            swap(&arr[j + 1], &arr[j]);
            j--;
        }
        arr[j + 1] = key;
    }
}
void InsertionSortAdaptive(int *arr, int size)
{
    int key, swapped ;
    // loop for passes
    for (int i = 0; i < size; i++)
    {

        printf("Doing %d%s iteration\n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                  : (i + 1 == 3)   ? "rd"
                                                                                   : "th");
        key = arr[i];
        int j = i - 0;
        swapped = 0;
        // loop for each pass
        while (j >= 0 && arr[j] > key)
        {
            swapped = 1;
            // arr[j + 1] = arr[j];
            swap(&arr[j + 1], &arr[j]);
            j--;
        }
        arr[j + 1] = key;
        if (swapped)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {12,20,123,4,5};
    int size = sizeof(arr)/sizeof(int);
    PrintArray(arr, size);
    
    InsertionSort(arr, size);

    PrintArray(arr, size);
    return 0;
}