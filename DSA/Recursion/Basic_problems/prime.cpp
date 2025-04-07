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
bool isPrimeHelper(int n, int divisor)
{
    if (divisor > sqrt(n))
    {
        return true;
    }
    if (!(n % divisor))
    {
        return false;
    }
    return isPrimeHelper(n, divisor + 1);
}
bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    return isPrimeHelper(n, 2);
}
vector<int> getPrimeSeries(int n)
{
    vector<int> ans;
    for (int i = 2, c = 0; c < n; ++i)
    {
        if (isPrime(i))
        {
            ans.pb(i);
            c++;
        }
    }
    return ans;
}
vector<int> getNonPrimeSeries(int n)
{
    vector<int> ans;
    for (int i = 2, c = 0; c < n; ++i)
    {
        if (!isPrime(i))
        {
            ans.pb(i);
            c++;
        }
    }
    return ans;
}
int main()
{
    vector<int> primelist = getPrimeSeries(10);
    vector<int> nonprimelist = getNonPrimeSeries(10);
    for (int i : primelist)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : nonprimelist)
    {
        cout << i << " ";
    }
    return 0;
}