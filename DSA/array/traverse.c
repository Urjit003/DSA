#include <stdio.h>
#include <stdlib.h>
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
void PrintArray(int *arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d]", arr[i]);
    }
    printf("\n");
}
int main() {    
    int *arr = CreateArray(10);
    PrintArray(arr, 10);
return 0 ;
}