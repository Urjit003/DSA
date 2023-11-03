#include<iostream>
#include<stdlib.h>
// #include <cstdlib>
// #include <ctime>
using namespace std;
template <typename T> void Sort(T *a , T *b);
template <typename T> void BubbleSort(T *arr, int size) ;
template <typename T> void SelectionSort(T *arr, int size) ;
template <typename T> void InsertionSort(T *arr, int size) ;
template <typename T> void PrintArray (T *arr,int size);
template <typename T> void PrintArray (T *arr,int size)  {
    for (auto i = 0; i < size; i++)
    {
        cout << "["<<arr[i]<< "]";
    }
    cout <<endl;
}
template <typename T> void SWAP(T *a , T *b) {
    T c = *a;
    *a = *b ;
    *b = c;
    
}
template <typename T> void BubbleSort(T *arr, int size) {
    int IsSorted = false;
    for (int i = 0; i < size; i++)
    {
        IsSorted = true;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j+1]) {
                SWAP<T>(&arr[j],&arr[j+1]);
                IsSorted = false;
            }
        }
        if(IsSorted) {
            break;
        }
    }
    
}
template <typename T> void SelectionSort(T *arr, int size) {
    int IndexOfMin;
    for (int i = 0; i < size - 1; i++)
    {
        IndexOfMin = i;
        for (int j = i +1 ; j < size ; j++)
        {
            if (arr[j] < arr[IndexOfMin])
            {
                IndexOfMin = j ;
            }
            
        }
        SWAP<>(&arr[i],&arr[IndexOfMin]);
    }
    
}
template <typename T> void InsertionSort(T *arr, int size) {
    T key ;
     int j;
    // Loop for passes
    for (int i = 0; i < size; i++)
    {
        key = arr[i];
        j = i -1;
        // loop for each passes 
        while (j>= 0 && arr[j] > key)
        {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main (){
    const int size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i]= rand() % 100;
    }
    
    PrintArray<>(arr,size);
    InsertionSort<>(arr, size);
    PrintArray<>(arr,size);
return 0;
}