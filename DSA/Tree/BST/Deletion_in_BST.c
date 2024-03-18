#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} node;
node *Add(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}
void PreOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);

        printf("%d \n", root->data);
    }
}
void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d \n", root->data);
        InOrder(root->right);
    }
}
void FreeTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    FreeTree(root->left);
    FreeTree(root->right);
    free(root);
}
int IsBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!IsBST(root->left))
        {
            return 0; // false
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return IsBST(root->right);
    }
    else
    {
        return 1;
    }
}
node *FindElement(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (val == root->data)
    {
        return root;
    }
    else if (val < root->data)
    {
        return FindElement(root->left, val);
    }
    else
    {
        return FindElement(root->right, val);
    }
}
node *DeleteLeaf(node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL)
    {
        if (val < root->data)
        {
            root = root->left;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else if (root->left == NULL && root->right == NULL && root->data == val)
        {
            free(root);
            return NULL;
        }
    }
    return root;
}
int main()
{
    node *p = Add(50);
    node *p1 = Add(40);
    node *p2 = Add(60);
    node *p3 = Add(20);
    node *p4 = Add(45);
    node *p5 = Add(55);
    node *p6 = Add(70);

    // what the tree looks like
    //             50
    //           /   \
    //          40    60
    //         / \    / \
    //        20  45  55 70

    // Linking

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;
    printf("Before deletion \n");
    InOrder(p);
    p = DeleteLeaf(p, 20);
    printf("After deletion \n");
    InOrder(p);
    return 0;
}