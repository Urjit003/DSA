#include <iostream>
#include <stdlib.h>
using namespace std;

void DisplayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int* DisplayThreeLargest(int arr[], int size)
{
    // 1) Initialize the largest three elements as minus infinite.
    // first = second = third = -∞

    // 2) Iterate through all elements of array.
    // a) Let current array element be x.
    // b) If (x > first)
    //     {
    //         // This order of assignment is important
    //         third = second
    //         second = first
    //         first = x
    //     }
    // c)  Else if (x > second and x != first)
    //     {
    //         third = second
    //         second = x
    //     }
    // d)  Else if (x > third and x != second)
    //     {
    //         third = x
    //     }

    // 3) Print first, second and third.
    int *returnarr = new int[3];
    if (size < 3)
    {
        cout <<"Size too low";
        exit(1);
    }
    int first, second, third;
    first = second = third = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        int x = arr[i];
        if (x > first)
        {
            third = second;
            second = first;
            first = x;
        }
        else if (x > second && x != first)
        {
            third = x;
            second = x ;
        }
        else if (x > third && x != second)
        {
            third = x;
        }
    }
    // cout << "the first most element is : "<< first << endl;
    // cout << "the second most element is : "<< second << endl;
    // cout << "the third most element is : "<< third << endl;

    returnarr[0]= first;
    returnarr[1]= second;
    returnarr[2]= third;

    return returnarr;
}
void setArrayElements(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element for " << i << " : ";
        cin >> arr[i];
    }
}
int main()
{
    // int arr[] = {1, 24, 45, 67, 88};
    int size;
    cout << "Enter the size of your array\n";
    cin >> size;
    int *arr = new int[size];
    setArrayElements(arr, size);
    DisplayArray(arr, size);
    cout << endl;
    int *newarr = DisplayThreeLargest(arr, size);
    DisplayArray(newarr,3);

    delete[] arr ;
    delete[] newarr;
    return 0;
}