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
void printHourGlass(vector<vector<int>> &arr)  {
    int n = arr.size() ;
    ll sum = 0;
    int count =  0; 
    for(int i = 0 ; i < n-2 ;++i) {
        for(int j = 0 ; j < n-2 ; j++) { 
            sum += arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            cout<<arr[i][j]<<"  "<<arr[i][j+2]<< "  "<<arr[i][j+2]<<endl;
            cout << "   "<<arr[i+1][j+1]<<endl;
            cout<<arr[i+2][j]<< "  "<< arr[i+2][j+1]<<"  "<<arr[i+2][j+2]<<endl;
            count ++;
            cout << "sum of this hourglass is : " <<sum <<endl;
        }
    }
    cout << "total hourglasses found are : " << count ; 
}
int main() {

   vector<vector<int>> arr= {
        { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
    };
    
    printHourGlass(arr);
    return 0;
}