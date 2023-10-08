#include <stdio.h>
#include <stdlib.h>
int *CreateArray(int size);
int PrintArray(int *arr, int size);
void LinearSearch(int *arr, int size, int element);
void lmao(int a , int b);
int PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d is the %d%s element \n", arr[i], i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                             : (i + 1 == 3)   ? "rd"
                                                                                              : "th");
    }
}
int *CreateArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter element for %d \n", i + 1);
        scanf("%d", &arr[i]);
    }
    return arr;
}
void LinearSearch(int *arr, int size, int element)
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("%d found at %d\n", element, i + 1);
            found = 1;
            return;
        }
    }
    if (!found)
    {
        printf("%d couldn't be found \n", element);
        printf("Enter a new element to serach \n");
        scanf("%d", &element);
        LinearSearch(arr, size, element);
    }
}
int main()
{
    int size, element;
    printf("Enter the size of your array \n");
    scanf("%d", &size);
    int *arr = CreateArray(size);
    PrintArray(arr, size);
    printf("Enter the element to search \n");
    scanf("%d", &element);
    LinearSearch(arr, size, element);
    return 0;
}