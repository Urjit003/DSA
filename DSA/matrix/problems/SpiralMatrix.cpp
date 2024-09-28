#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define vii vector<vector<ll>>
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
string printSpiral(vector<vector<int>> &matrix)
{
    // Check if the matrix is empty
    if (matrix.empty())
        return "[]";

    // num of rows
    int m = matrix.size();    // num of rows
    int n = matrix[0].size(); // num of columns
    string ans = "";
    ans += "[";
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    bool firstElement = true; // Flag to handle commas correctly

    while (top <= bottom && left <= right)
    {
        // Print top row
        for (int i = left; i <= right; ++i)
        {
            if (!firstElement)
                ans += ",";
            ans += to_string(matrix[top][i]);
            firstElement = false;
        }
        ++top;

        // Print right column
        for (int i = top; i <= bottom; ++i)
        {
            if (!firstElement)
                ans += ",";
            ans += to_string(matrix[i][right]);
        }
        --right;

        // Print bottom row
        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                if (!firstElement)
                    ans += ",";
                ans += to_string(matrix[bottom][i]);
            }
            --bottom;
        }

        // Print left column
        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                if (!firstElement)
                    ans += ",";
                ans += to_string(matrix[i][left]);
            }
            ++left;
        }
    }

    ans += "]";
    return ans;
}
vector<vector<ll>> generateSpiralMatrix(int n)
{
    vii ans(n, vi(n));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    ll x = 1;
    while (top <= bottom && left <= right)
    {
       
        for (int i = left; i <= right; ++i)
        {
            ans[top][i] = x++;
        }
        ++top;
        for (int i = top; i <= bottom; ++i)
        {
            ans[i][right] = x++;
        }
        --right;
        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                ans[bottom][i] = x++;
            }
            --bottom;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[i][left] = x++;
            }
            ++left;
        }
    }
    return ans;
}
int main()
{
    vii ans ;
    ans = generateSpiralMatrix(5);  
    // for(auto i :ans) {
    //     for(auto x : i) {

    //     cout << x << " " ;
    //     }
    //     cout << endl; 
    // }
    for(auto row : ans) {
        for_each(row.begin(),row.end() ,[](int ele){
            cout << ele << " " ;
        });
        cout << endl;
    }
    return 0;
}