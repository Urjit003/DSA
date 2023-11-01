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
template <typename T> void InsertionSort(T *arr,int size) {
    int key;
    for (T i = 1; i < size; i++)
    {
           printf("Doing %d%s iteration\n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                  : (i + 1 == 3)   ? "rd"
                                                                                   : "th");
        
        key = arr[i];
        T j = i -1;
        while (j>=0 && arr[j] > key)
        {
            Swap(&arr[j+1],&arr[j]);
            j--;
        }
        arr[j+1] = key;
    }
    
}
template <typename T> 
void InsertionSortOPT(T *arr,int size) {
    
    int key;
    for (T i = 0; i < size; i++)
    {
          printf("Doing %d%s iteration\n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                  : (i + 1 == 3)   ? "rd"
                                                                                   : "th");
                                                        
        key = arr[i];
        T j = i -1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main (){
    int arr[]= {1,2,3,5,4};
    auto size = sizeof(arr)/sizeof(arr[0]);
    PrintArray<>(arr,size);
    InsertionSortOPT<>(arr,size);
    PrintArray<>(arr,size);
return 0;
}