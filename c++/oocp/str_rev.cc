#include<iostream>
#include<stdlib.h>
using namespace std;
template <typename T> void PrintArray (T *arr,int size)  {
    for (auto i = 0; i < size; i++)
    {
        cout << "["<<arr[i]<< "]";
            if(arr[i]== '\0' && i !=0) {
                break;
        }
            
    }
    cout <<endl;
}
template <typename T> void Swap (T *a, T *b) {
    T temp = *a ;
    *a = *b ;
    *b = temp;
}
template <typename T> void REV(T *str,int length) {

    for (int i = 0, j = length - 1; i < j ; i++ , --j)
    {
        Swap(&str[i],&str[j]);
    }
    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = i+1; j <length; j++)
    //     {   
    //         if(i<j) {
    //             Swap(&str[i],&str[j]);
    //        }
    //     }
    // }
    
    
    
}
int main (){
// char name [] = {'a','b','c','d','e','f'};
char name[] = "Urjit";
int size = sizeof(name) / sizeof(name[0]);
    PrintArray(name,size);
    REV(name,size);
    PrintArray(name,size);
return 0;
}