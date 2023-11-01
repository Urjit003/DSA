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
T *SelectionSort(T *arr, int size) {
    
    return arr;
}
int main (){
    double arr[]= {1.1,2.1,3.4,-0.1,-0.5,0,5.5,4.2,.41,.8,.6};
    int size = sizeof(arr)/sizeof(arr[0]);
    PrintArray<>(arr,size);
    double * Sarr = SelectionSort<double>(arr, size);
    PrintArray<>(Sarr,size);
return 0;
}