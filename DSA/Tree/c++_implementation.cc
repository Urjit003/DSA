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
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree
{
public:
    Node *root;
    BinaryTree()
    {
        root = nullptr;
    }
    Node *insert(Node *root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        cout << "Insert " << data << " left or right of " << root->data << " (l/r) : " << flush;
        char direction;
        cin >> direction;
        if (direction == 'l')
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
    void inOrderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    void preOrderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
            return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
};
class BinarySearchTree : public BinaryTree
{
public:
    Node *insertBST(Node *root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        if (data < root->data)
        {
            root->left = insertBST(root->left, data);
        }
        else if (data > root->data)
        {
            root->left = insertBST(root->left, data);
        }
        return root;
    }
};
int main()
{
    BinaryTree t1;
    t1.root = t1.insert(t1.root, 10);
    t1.root = t1.insert(t1.root, 40);
    t1.root = t1.insert(t1.root, 82);
    t1.root = t1.insert(t1.root, 818);
    cout << "In-order Traversal: ";
    t1.inOrderTraversal(t1.root);
    cout << "\nPre-order Traversal: ";
    t1.preOrderTraversal(t1.root);
    cout << "\nPost-order Traversal: ";
    t1.postOrderTraversal(t1.root);

    cout << "\n\nBinary Search Tree: ";
    BinarySearchTree bst;
    bst.root = bst.insertBST(bst.root, 10);
    bst.root = bst.insertBST(bst.root, 5);
    bst.root = bst.insertBST(bst.root, 20);
    bst.root = bst.insertBST(bst.root, 3);
    bst.root = bst.insertBST(bst.root, 7);

    cout << "\nBST In-order Traversal: ";
    bst.inOrderTraversal(bst.root);
    cout << "\nBST pre-order Travsersal :" ;
    bst.preOrderTraversal(bst.root);
    cout << endl;
    return 0;
}