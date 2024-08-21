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
void func3() {
    printf("Hello from function 3\n");
}
void func2() {
    func3();
    printf("Hello from function 2\n");
}
void func1() {
    func2();
    printf("Hello from function 1\n");
}
void func() {
    func1();
    printf("hello from function 0\n");
}
int main() {
    func();
    return 0;
}