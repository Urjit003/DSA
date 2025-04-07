#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long int
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vint vector<int>
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
vvi transPoseMatrix(vvi arr)
{
    vvi ans(arr);

    loop(i, 0, arr.size())
    {
        loop(j, 0, arr.size())
        {
            ans[j][i] = arr[i][j];
        }
    }
    return ans;
}

int main()
{
    vvi ans = transPoseMatrix({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    });
    for(auto i : ans) {
        for (auto j : i) {
            cout << j << " " ;
        }
        cout << endl;
    }
    return 0;
}