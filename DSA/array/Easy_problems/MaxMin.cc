// Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
// Output: arr[] = {7, 1, 6, 2, 5, 3, 4}

// Input: arr[] = {1, 2, 3, 4, 5, 6}
// Output: arr[] = {6, 1, 5, 2, 4, 3}
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<int> AlternateArray(vector<int> &arr);
void PrintVector(vector<int> arr);

void PrintVector(vector<int> arr)
{
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}
vector<int> AlternateArray(vector<int> &arr)
{
    int n = arr.size();
    int maxi = n - 1;
    int mini = 0;
    int me = arr[maxi] + 1;
    for (int i = 0; i < n; i++)
    {
        // int j = i ;
        if (i % 2 == 0)
        { /* even*/
            arr[i] = arr[i] + (arr[maxi] % me) * me;
            maxi--;
        }
        else if (i % 2 != 0)
        { /*Odd*/
            arr[i] = arr[i] + (arr[mini] % me) * me;
            mini++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] /= me;
    }

    return arr;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    PrintVector(arr);
    // cout << arr.size();
    vector<int> arr_altr = AlternateArray(arr);
    PrintVector(arr_altr);
    return 0;
}