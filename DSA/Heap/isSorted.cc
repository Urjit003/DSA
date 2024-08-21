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
bool isSorted(vi vec)
{
    for (auto i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i + 1] < vec[i])
            return false;
    }

    return true;
}
int main()
{
    vi arr;
    for (int i = 0; i < 1000; i++)
    {
        arr.pb(rand() % 100000);
    }
    logarr(arr, 0, arr.size());
    cout << isSorted(arr);
    return 0;
}