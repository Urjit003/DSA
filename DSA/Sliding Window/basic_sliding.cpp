#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long int
#define vi vector<ll>
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
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int maxOfFour(int a , int b , int c , int d) {
    return max(a,max(b,max(c,d)));
}
// Question 1
int maxSumSlidingWindow(vi arr, int k, int n)
{
    int maxSum = 0, windowSum = 0;
    loop(i, 0, k)
    {
        windowSum += arr[i];
    }
    maxSum =  windowSum ;

    loop(i , k ,n) {
        windowSum += arr[i] - arr[i-k] ;
        maxSum = max(maxSum, windowSum) ;
        // logarr(arr,0,n-1) ;
    }
    return maxSum;
}
// Question 2 
/*vector<int> firstNegative(vi arr, int k , int n) {
    vector<int> sum ; 
    loop(i , 0 , n ) {
        if(arr[i] < 0) {
            sum.emplace_back(arr[i]);
        }
    }

    loop(i , k , n) {
        if(arr[i] < 0) {
            sum.emplace_back(arr[i]);
        }
    }
    return sum ;
}*/

// QUEUE SOLUTION 
vint firstNegatives(vi arr, int k ,int n) {
    vint sum ;
    queue<int> q; 
    loop(i , 0 ,k) {
        if(arr[i] < 0) q.push(i) ;
    }
    loop(i , k , n+1) {
        sum.push_back(q.empty() ? 0 : arr[q.front()]); 

        while(!q.empty() && q.front() <= i -k) {
            q.pop();
        }
        if (i < n && arr[i] < 0) {
            q.push(i) ;
        }
    }
    return sum ;
}
// sum of all sub arrays with sliding window of K 
vint sumOfSubArrays(vi arr , int k , int n) {
    vint ans ; 
    int windowSum = 0 ; 
    loop(i,0,k) {
        windowSum+=arr[i] ;
    }
    ans.push_back(windowSum) ;

    loop(i,k,n) {
        // 6 = 6 + 4 [i=3] - 1[(i=3 - k=3)=0]
        windowSum+=arr[i] - arr[i-k] ;
        ans.pb(windowSum);
    }
    return ans ;
}

int main()
{
    vi arr = {1, 2, 3, 4, 5, 6, 7, 8} ;
    int k = 3; 
    int n = arr.size() ;
    vector<int> sum =  sumOfSubArrays(arr,k,n); 
    // logarr(sum,0,sum.size()-1) ;
    // cout << maxOfFour(111,211,1333,40000) ;
    cout << arr[rand()/100] << endl;
    cout << arr[rand() % 8] ;
    return 0;
}