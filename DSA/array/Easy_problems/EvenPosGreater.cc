#include<iostream>
#include<stdlib.h>
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
void rearrange(int *arr, int size) {
    for (int i = 0; i < size-1; i+=2)
    {
        if(arr[i] < arr[i+ 1]){
            swap(&arr[i+1],&arr[i]);
        }
    }
    
}
int main (){
    int arr[] = { 1, 3, 2, 2, 5 };
    int size = sizeof(arr)/sizeof(int);
    rearrange(arr,size);
    PrintArray(arr,size);
    return 0;
}