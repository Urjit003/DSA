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
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d is the %d%s element\n", arr[i], i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                            : (i + 1 == 3)   ? "rd"
                                                                                             : "th");
    }
    printf("\n");
}
void SelectionSort(int *arr, int size)
{
    int IndexOfMin;
    for (int i = 0; i < size - 1; i++)
    {
        IndexOfMin = i;
        for (int j = i +1; j < size; j++)
        {   
            if (arr[j] < arr[IndexOfMin]) {
                IndexOfMin = j ;
            }
        }
        swap(&arr[i],&arr[IndexOfMin]);
    }
}
int main()
{
    // -1  00   01   02   03   04
    //     03,  05,  02,  13,  12
    int size;
    printf("Enter the size of your array \n");
    scanf("%d", &size);
    int *a = MakeArry(size);
    SelectionSort(a, size);
    PrintArray(a, size);
}