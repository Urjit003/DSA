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
int main()
{
    node *p = Add(10);
    node *p1 = Add(8);
    node *p2 = Add(12);
    node *p3 = Add(7);
    node *p4 = Add(9);
    node *p5 = Add(11);
    node *p6 = Add(13);

    // what the tree looks like
    //           10
    //          /  \
    //         8    12
    //        / \   / \
    //       7   9  11 13

    // Linking

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    InOrder(p);
    if (!IsBST(p))
    {
        printf("no this isn't a BST \n");
    }
    else
    {
        printf("yes this is a BST \n");
        InOrder(p);
    }
    FreeTree(p);
    return 0;
}