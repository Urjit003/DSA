#include <iostream>
#include <stdlib.h>
using namespace std;
int *MakrArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element for " << i + 1 << ": ";
        cin >> arr[i];
    }
    return arr;
}
void PrintArray_Rev(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    printf("\n");
}
void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    printf("\n");
}
void SortArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int PrintLargest(int *arr, int size)
{
    if (size < 2)
    {
        exit(1);
    }
    SortArray(arr, size);
    int Largest = arr[size - 1];
    return Largest;
}
int PrintSecondLargest(int *arr, int size)
{
    if (size < 2)
    {
        exit(1);
    }
    SortArray(arr, size);
    int secondLargest = arr[size - 2];
    return arr[size - 2];
    /*for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] != arr[size - 1])
        {
            cout << "the second largest element is " << arr[i];
            return;
        }
    }*/
}

int main()
{
    cout << "Enter the size of your array: ";
    int size;
    cin >> size;
    int *arr = MakrArray(size);
    SortArray(arr,size);
    PrintArray(arr,size);
    int secondlargest = PrintLargest(arr,size);
    cout << "The second largest element in the provided array is : " << secondlargest;
    return 0;
}