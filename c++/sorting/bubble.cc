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
    for (int i = 0; i < size; i++)
    {
        cout<< "Doing " <<i <<" iteration ." <<endl;
        for (int j = 0; j < size - 1 -i ; j++)
        {
            if(arr[j]>arr[j +1 ]){ 
                Swap(&arr[j],&arr[j+1]);
            }
        }
    }
    
}
template <typename T> void BubbleOPT(T *arr,int size) {
    bool IsSorted = 0;
    for (int i = 0; i < size; i++)
    {
        cout<< "Doing " <<i <<" iteration" <<endl;
        IsSorted = true;
        for (int j = 0; j < size - 1 -i ; j++)
        {
            if(arr[j]>arr[j +1 ]){ 
                Swap(&arr[j],&arr[j+1]);
                IsSorted = false;
            }
        }
        if (IsSorted) {
            break;
        }
    }
    
}

int main (){
    int arr[]= {4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    PrintArray(arr,size);
    BubbleOPT(arr, size);
    PrintArray(arr,size);
return 0;
}