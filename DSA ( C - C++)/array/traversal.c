#include "stdio.h"
#include "stdlib.h"

int main(void)
{
    int n;
    printf("\nEnter the size of your array : ");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Error: failed to allocate memory\n");
        exit(1);
    }
    int UsingSize;
    printf("Enter the size of how many indexes to use : ");
    scanf("%d", &UsingSize);
    // 1000 , 5
    while (UsingSize > n)
    {
        printf("UsingSize is greater than given size.\nEnter valid UsingSize: ");
        scanf("%d", &UsingSize);
    }
    for (int i = 0; i < UsingSize; i++)
    { 
        printf("Enter element for %d :", i + 1);
        scanf("%d", &array[i]);
    }
    printf("The array is \n");
    for (int i = 0; i < UsingSize; i++)

    {
        printf("%d [%d] | ",i,array[i]);
        // printf("%d : %d and its address is %d \n", i + 1, array[i],&array[i]);
    }
    free(array);
    return 0;
}