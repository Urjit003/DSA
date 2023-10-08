#include "stdio.h"
#include "stdlib.h"

int RevArray (int arr[],int start , int end) {
int temp ;
    // 1,2,3,3,34,4 
    // end = 6
    // start = 0
    while (end > start)
    {
        // temp = 1 
        temp = arr[start];

        // arr[0] = arr[size -1 ]
        arr[start] = arr[end];

        // arr[size-1] = 1 <temp>
        arr[end]= temp;

        // size +=1 
        start++;

        //[size-1] -+ 1
        end--; 
    }
}
void PrintArray(int arr[] , int size){
     printf("Index : Element\n");
    for (int i = 0; i < size; i++)
    {
        printf("   %d  :  %d\n", i, arr[i]);
    }
    printf("\n");   
}

int main () {
    int arr[] = {1,2,3,3,34,4};
    int size = sizeof(arr) / sizeof(int);
    PrintArray(arr,size);
    RevArray(arr,0, size-1);
    printf("\n");
    PrintArray(arr,size);
    return 0 ;
}