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
string digitExtract(int v)
{
    string ans = "";
    while (v > 0)
    {
        int lastDigit;
        lastDigit = v % 10;
        ans +=to_string(lastDigit);
        v /= 10;
    }
    return ans;
}
int main()
{
    int x = 12345;
    string y = digitExtract(x);

    cout << y << "\n";
    return 0;
}