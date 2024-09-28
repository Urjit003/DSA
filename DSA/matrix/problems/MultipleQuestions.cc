#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
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
bool SearchInMatrix(vector<vector<int>> mat, int x)
{

    // input:
    // {
    //     {1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, { 10, 13, 14, 17 }
    // }
    // Target:  5
    // Output : True
    int isFound = false;
    for (auto row : mat)
    {
        for (auto col : row)
        {
            if (x == col)
                return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3}, {5, 23, 163}, {853, 33, 454}
};
bool ans = SearchInMatrix(mat, 90);
cout << ans;
return 0;
}