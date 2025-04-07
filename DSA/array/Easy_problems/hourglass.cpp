#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr, a, b)           \
    for (int i = (a); i < (b); i++) \
        cout << (arr[i]) << " ";    \
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
vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int n = vec.size();
ll sum = 0;
void solve()
{
    for (int i = (0); i < (n - 2); i++)
    {
        for (int j = (0); j < (n - 2); j++)
        {
            cout << vec[i][j] << " " << vec[i][j + 1] << " " << vec[i][j + 2] << endl;
            cout << "  " << vec[i + 1][j + 1] << endl;
            cout << vec[i + 1][j] << " " << vec[i + 1][j + 1] << " " << vec[i + 2][j + 2];
            sum += vec[i][j] + vec[i][j + 1] + vec[i][j + 2] + vec[i + 1][j + 1] + vec[i + 1][j] + vec[i + 1][j + 1] + vec[i + 2][j + 2];
        }
        cout << endl;
    }
    cout << "sum of the found hourglass is : " << sum << endl;
}
int main()
{
    cout << n << endl;
    solve();
    return 0;
}