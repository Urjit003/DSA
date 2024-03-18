#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *arr,int size)
{
    for (int i = 0; i <= size; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
// int *AddToEnd(int *arr, int data)
// {
//     int *ptr = arr;
//     int temp = data;
//     int size = sizeof(arr) / sizeof(int);
//     size++;
//     for (int i = 0; i <= size; i++)
//     {
//         ptr[size] = data;
//     }
//     return arr;
// }
// int *AddToEnd(int *arr,int data) {
//     int *Duplicate=arr ;
//     int size = sizeof(arr)/sizeof(int);
//     for (int i = 0; i < size; i++)
//     {
//         Duplicate[i] = arr[i];
//     }
//     size ++;
//     Duplicate[size] = data;
//     arr=Duplicate;
//     return Duplicate;
// }
int *AddToEnd(int *arr, int data,int size)
{
    int *Duplicate = (int *) malloc((size +1) * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        Duplicate[i] =arr[i];
    }
    Duplicate[size] = data;
    return Duplicate;
}
int main()
{
    int A[] = {10, 20, 30};
    PrintArray(A,3);
    int *NewArry= AddToEnd(A, 40,4);
    

    PrintArray(NewArry,4);
    return 0;
}