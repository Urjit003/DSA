#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr, a, b)            \
    for (int i = (a); i <= (b); i++) \
        cout << (arr[i]) << " ";     \
    cout << endl;
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    int *arr = new int[100];
    int size = sizeof(arr) / sizeof(int);
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = rand() % 100;
    }
    logarr(arr, 0, size - 1);
    ++size;
    arr = new int[size];
    arr[size] = 222222;
    logarr(arr, 0, size);
    return 0;
}