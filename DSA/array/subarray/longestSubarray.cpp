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

int maxSumSubarray(vector<int>& nums, int k) {
    int windowSum = 0, maxSum = 0;

    // Calculate the sum of the first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    maxSum = windowSum;

    // Slide the window across the array
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];  // Add the new element and remove the old one
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
int smallestSubarrayWithSum(vector<int>& arr, int s ) {
    
}
int main() {
    vector<int> nums = {2, 1, 5, 2, 3, 2};
    int k = 3;
    cout << "Maximum sum of subarray of size " << k << " is: " << maxSumSubarray(nums, k) << endl;
    return 0;
}
