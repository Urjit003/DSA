#include<iostream>
#include<stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void SegOddEven(int arr[], int size ){
    int evenCount = 0;
    int oddCount = 0;
    
    // Count the number of even and odd elements
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    // Create dynamic arrays to hold even and odd elements
    int* even = (int *)malloc(evenCount * sizeof(int));
    // int* even = new int[evenCount];
    int* odd = new int[oddCount];
    
    int evenIndex = 0;
    int oddIndex = 0;
    
    // Separate even and odd elements into their respective arrays
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even[evenIndex++] = arr[i];
        } else {
            odd[oddIndex++] = arr[i];
        }
    }
    
    // Rearrange the original array with even elements first, followed by odd elements
    int i = 0;
    for (int j = 0; j < evenCount; j++) {
        arr[i++] = even[j];
    }
    for (int j = 0; j < oddCount; j++) {
        arr[i++] = odd[j];
    }
    
    // Deallocate memory for dynamic arrays
    delete[] even;
    delete[] odd;


}
int main (){
    int arr[]= {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    SegOddEven(arr,size);
    PrintArray(arr,size);
return 0;
}