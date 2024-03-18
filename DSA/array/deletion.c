#include <stdio.h>
void Deletion(int arr[], int size, int index)
{

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void Display(int arr[], int size)
{
        printf("Index : Element\n");
    for (int i = 0; i < size; i++)
    {
        printf("   %d  :  %d\n", i, arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    // int size = 7;
    Display(arr,size);
    Deletion(arr,size,1);
    size-=1;
    Display(arr,size);
    return 0;
}
