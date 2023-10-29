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
template <typename T> void Swap (T *a, T *b) {
    T temp = *a ;
    *a = *b ;
    *b = temp;
}
template <typename T> void Bubble(T *arr,int size) {
    bool swapped = 0;
    for (int i = 0; i < size; i++)
    {
        swapped = false;
        for (int j = 0; j < size - 1 -i ; j++)
        {
            if(arr[j]>arr[j +1 ]){ 
                Swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    
}

int main (){
    float arr[]= {1.01,2.02,.42,1.33,2.1232};
    int size = sizeof(arr)/sizeof(arr[0]);
    PrintArray(arr,size);
    Bubble(arr, size);
    PrintArray(arr,size);
return 0;
}