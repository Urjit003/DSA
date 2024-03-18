#include <stdio.h>

void Display(int arr[], int size)
{
    printf("Index : Element\n");
    for (int i = 0; i < size; i++)
    {
        printf("   %d  :  %d\n", i, arr[i]);
    }
    printf("\n");
}
void sortarray_d(int arr[], int size)
{
    // dec order
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void SortArray(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            // if current element is greater than next element, swap them
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int BinarySearch(int arr[], int size, int target)
{
    SortArray(arr, size);
    int low = 0, mid, high = size - 1, flag = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        // [4] > 1
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] == target)
        {
            return mid;
            flag = 1;
            break;
            // printf("Target[%d] found at %d\n",target,mid);
        }
        else if (!flag)
        {
            return 0;
        }
    }
}
int MakeArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        return (arr[i]);
    }
    return arr;
}
int main()
{
    // // Your code here
    // int arr[] = {MakeArray()};
    // int size = sizeof(arr)/sizeof(int);
    // int element;
    // SortArray(arr,size);
    // Display(arr,size);
    // printf("Enter the elemet:"); scanf("%d",&element);
    // printf("%d found at [%d]",element,BinarySearch(arr,size,element));
    int arr[] = {1, 3, 56, 60, 65, 701, 2223, 10444, 123, 23, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    Display(arr, size);
    SortArray(arr, size);
    Display(arr, size);
    printf("%d fount at [%d]\n", 701, BinarySearch(arr, size, 701));
}