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
constexpr int MAX = 100;
constexpr ll null = -1;
constexpr ll safe = 21;
ll memoTable[MAX];
void _init()
{
    for (int i = 0; i < MAX; i++)
    {
        memoTable[i] = null;
    }
}

ll factorial(int n)
{

    if (memoTable[n] == null)
    {
        if (n <= 1)
            memoTable[n] = 1;
        else
            memoTable[n] = n * factorial(n - 1);
    }
    return memoTable[n];
}
int main()
{
    static bool hasRan = false;
    if (!hasRan)
    {
        _init();
        hasRan = true;
    }
    for (int i = 0; i < safe; i++)
    {
        cout << "Factorial of " << i << " is : " << factorial(i) << endl;
    }
    return 0;
}