#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
bool IsSorted(T *arr, int size)
{
    for (auto i = 0; i < size; i++)
    {
        if ((arr[i] > arr[i + 1]))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    if (IsSorted(arr, size))
    {
        cout << "ARR IS SORTED \n";
    }
    else
    {
        cout << "ARR IS NOT SORTED \n";
    }
    return 0;
}