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
int Linear(int arr[],int size,int target) {
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target) {
            printf("%d found at %d\n",target,i);
            // break;
        }    

    }
}
int main() {
    // Your code here
    int arr[] = {1,12,34,56,67,90,122,12,56};
    int size = sizeof(arr)/sizeof(int);
    Display(arr,size);
    Linear(arr,size,12);
}