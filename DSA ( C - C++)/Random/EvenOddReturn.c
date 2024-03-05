/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int *EvenAndOdd(int *arr, int size)
{
    int *res = (int *) malloc(2 * size);
    int EvenCounter = 0, OddCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            res[0] = ++EvenCounter;
        }
        else
        {
            res[1] = ++OddCounter;
        }
    }
    return res;
    free(res);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8,11,19,21,23,25};
    int size = sizeof(arr) / sizeof(int);
    int *newarr = EvenAndOdd(arr, size);
    int newsize = sizeof(newarr) / sizeof(int);
    PrintArray(arr,size);
    printf("Even Numbers : [%d] , Odd Numbers [%d] \n",newarr[0],newarr[1]);  
    return 0;
}
