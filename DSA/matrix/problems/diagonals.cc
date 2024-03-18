// Given a 2D square matrix, print the Principal and Secondary diagonals.

// Examples :

// Input:
// 1 2 3 4
// 4 3 2 1
// 7 8 9 6
// 6 5 4 3
// Output:
// Principal Diagonal: 1, 3, 9, 3
// Secondary Diagonal: 4, 2, 8, 6

// Input:
// 1 1 1
// 1 1 1
// 1 1 1
// Output:
// Principal Diagonal: 1, 1, 1
// Secondary Diagonal: 1, 1, 1
#include <iostream>
#include <stdlib.h>
using namespace std;
const int n = 5;
void Principal(int (&arr)[n][n]);
void secondary(int (&arr)[n][n]);

void Principal(int (&arr)[n][n])
{
    cout << "Principal diagonals are"
         << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i][i] << " ";
        // for (int j = 0; j < n; j++)
        // {
        //     if (i == j)
        //     {
        //         cout << arr[i][j];
        //     }
        // }
    }
    cout << "\n";
}
void secondary(int (&arr)[n][n])
{
    cout << "secondary diagonals are"
         << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << (arr[i][n-i-1])<<" " ;
        // for (int j = 0; j < n; j++)
        // {
        //     if (i + j == (n - 1))
        //     {
        //         cout << arr[i][j];
        //     }
        // }
    }
    cout << "\n";
}
int main()
{
    int arr[n][n] = {
        {1, 2, 3, 4, 5},
        {4, 3, 2, 1, 6},
        {7, 8, 9, 6, 7},
        {6, 5, 4, 3, 8},
        {5, 7, 3, 6, 2}};
    Principal(arr);
    secondary(arr);
    return 0;
}