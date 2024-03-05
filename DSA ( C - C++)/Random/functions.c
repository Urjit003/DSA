#include <stdio.h>
#include <stdlib.h>
int *MakeArray(int size);
void DisplayArray(int arr[], int size);
int main()
{
    int size = 3;
    int *arr = MakeArray(size);
    DisplayArray(arr,size);
    return 0;
}   
int *MakeArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter value for index %d \n", i + 1);
        scanf("%d", &arr[i]);
    }
    return arr;
}
void DisplayArray(int *arr, int size)
{
    printf("Index : Element\n");
    for (int i = 0; i < size; i++)
    {
        printf("   %d  :  %d\n", i+1, arr[i]);
    }
    printf("\n");
}