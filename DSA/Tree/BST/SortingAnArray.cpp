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
struct TreeNode
{
    int value;
    TreeNode *left, *right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
TreeNode *insert(TreeNode *root, int value)
{
    if (!root)
    {
        return new TreeNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void InOrderTraversal(TreeNode *root, int *arr, int &index)
{
    if (root)
    {
        InOrderTraversal(root->left, arr, index);
        arr[index++] = root->value;
        InOrderTraversal(root->right, arr, index);
    }
}
void treesort(int arr[], int n)
{
    TreeNode *ptr = nullptr;
    for (int i = 0; i < n; i++)
    {
        ptr = insert(ptr, arr[i]);
    }
    int index = 0;
    InOrderTraversal(ptr, arr, index);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *arr = new int[INT_MAX];
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
    
    cout << "Original array" << endl;
    printArray(arr,n);

    treesort(arr,n);

    cout << "sorted array " << endl;
    printArray(arr,n);

    return 0;
}