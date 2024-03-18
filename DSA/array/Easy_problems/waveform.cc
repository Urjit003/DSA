#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void Sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}void RSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
void WaveSort(int *arr, int size)
{
    // Sort the array.
    // Traverse the array from index 0 to N-1, and increase the value of the index by 2.
    // While traversing the array swap arr[i] with arr[i+1].
    // Print the final array.
    RSort(arr, size);
    for (int i = 0; i < size - 1; i += 2)
    {
        swap(&arr[i], &arr[i + 1]);
    }
}
int main()
{
    int arr[] = {5,10,20,50,100,80,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    WaveSort(arr,size);
    PrintArray(arr,size);
    return 0;
}