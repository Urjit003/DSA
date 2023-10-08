#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SortArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] < a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}
int main()
{
    int a[] = {1, 2, 4, 44, 4, 123, 13, 123}; // 8
    int size = sizeof(a) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        printf("%d \n", a[i]);
    }
    
    return 0;
}