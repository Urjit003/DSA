#include<iostream>
#include<stdlib.h>
using namespace std;
template <typename T> void PrintArray (T *arr,int size)  {
    for (auto i = 0; i < size; i++)
    {
        cout << "["<<arr[i]<< "]";
    }
    cout <<endl;
}

template <typename T>
T *InsertionSort(T *arr, int size) {
    T key ; int j ,i;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i -1 ;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
    }
    return arr;
}
int main (){
    double arr[]= {1.1,2.1,3.4,-0.1,-0.5,0,5.5,4.2,.41,.8,.6};
    int size = sizeof(arr)/sizeof(arr[0]);
    PrintArray<>(arr,size);
    double * Sarr = InsertionSort<double>(arr, size);
    PrintArray<>(Sarr,size);
    
return 0;
}