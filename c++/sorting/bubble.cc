#include<iostream>
#include<stdlib.h>
using namespace std;
template <typename T> void PrintArray (T *arr,int size)  {
    for (auto i = 0; i < size; i++)
    {
        cout << "<"<<arr[i]<< ">";
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
    string arr= "([)]";

    int size = sizeof(arr)/sizeof(string);
    PrintArray(&arr[0], arr.length());
    Bubble(&arr[0],  arr.length());
    PrintArray(&arr[0], arr.length());
return 0;
}