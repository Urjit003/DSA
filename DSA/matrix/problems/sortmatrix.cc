// 3. Sort the given matrix:
// Given a n x n matrix. The problem is to sort the given matrix in strict order. Here strict order means that the matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, where 1 <= i <= n-1, the first element of row ‘i’ is greater than or equal to the last element of row ‘i-1’.

// Examples:

// Input : mat[][] =      { {5, 4, 7},
//                          {1, 3, 8},
//                         {2, 9, 6} }
// Output :     1 2 3
//              4 5 6
//              7 8 9
// Solution :
// The idea to solve this proble is Create a temp[] array of size n^2. Starting with the first row one by one copy the elements of the given matrix into temp[]. Sort temp[]. Now one by one copy the elements of temp[] back to the given matrix.
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 10
void SortMatrix(int arr[SIZE][SIZE], int n)
{
    int temp[n * n];
    int k = 0;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            temp[k++] = arr[i][j];
        }
    }
    sort(temp, temp + k);
    k = 0;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            arr[i][j] = temp[k++];
        }
    }
}
void printMat(int mat[SIZE][SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int arr[SIZE][SIZE] = {{5, 4, 7},
                           {1, 3, 8},
                           {2, 9, 6}};
    int n = 3;
    cout <<"\nOriginal Matrix:\n";
    printMat(arr,n);
    SortMatrix(arr,n); 
    cout <<"\nSorted Matrix:\n";
    printMat(arr,n);
    return 0;
}