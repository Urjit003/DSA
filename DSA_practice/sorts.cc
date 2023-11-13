#include<iostream>
#include<stdlib.h>
using namespace std;
template <typename T> void PrintArray(T *arr , int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "["<<arr[i]<<"]";
    }
    cout <<endl;
    
}
template <typename T> void SWAP(T *a , T *b) {
    T c = *a;
    *a = *b ;
    *b = c;
}
template <typename T>  int IsSorted (T *arr , int size) {
    for (int i = 0; i <size-1; i++)
    {
        if(arr[i] > arr[i+1] ) {
            return 0; // if i+1 > i then its not sorted

        }
    }
    cout << endl;
    return 1;
}
template <typename T> void InsertionSort(T *arr, int size ) {
    T key ; int j ;
    for (int i = 0; i < size ; i++)
    {
        key = arr[i] ;
        j = i-1 ;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1]  = arr[j] ;
            j --;
        }
        arr[j+1] = key;
    }
    
}
template <typename T> void SelectionSort(T *arr, int size ) {
    int IndexOfMin;
    for (int i = 0; i < size -1; i++)
    {
        IndexOfMin = i ;
        for (int j = i +1 ; j < size; j++)
        {
            if (arr[j] < arr[IndexOfMin])
            {
                IndexOfMin = j ;
            }
            
        }
        SWAP<>(&arr[i],&arr[IndexOfMin]);
    }
    
}
template <typename T> void BubbleSort(T *arr , int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                SWAP<T>(&arr[j],&arr[j+1]);
            }   
        }   
    }
}
int main (){
    int size ;
    cin>> size;
    int *arr;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 600;
    }
    
    PrintArray(arr,size);
    if(IsSorted(arr,size)) {cout << "List sorted"<< endl;}
    InsertionSort(arr,size);
    if(IsSorted(arr,size)) {cout << "List sorted"<< endl;}
    PrintArray(arr,size);
return 0;
}
