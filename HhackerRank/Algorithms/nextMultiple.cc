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
double returnNextMultiple(int n, int mul)
{
    if (n % mul == 0)
    {
        return 0;
    }
    for (n; n % mul != 0; n++)
        ;
    return n;
}
int main()
{
    int n = 73;
    cout << "next multiple of " << n << " is : " << returnNextMultiple(n, 5) << endl; // 75
    return 0;
}