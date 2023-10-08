#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
node *Add(int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n != NULL)
    {
        n->data = data;
        n->left = NULL;
        n->right = NULL;
    }
}
void PreOrderTraverse(node *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->data);
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}
void PostOrderTraverse(node *root)
{
    if (root != NULL)
    {
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        printf("%d \n", root->data);
    }
}
void InOrderTraverse(node *root)
{
    if (root != NULL)
    {
        InOrderTraverse(root->left);
        printf("%d \n", root->data);
        InOrderTraverse(root->right);
    }
}

int main()
{
    node *p = Add(0);
    node *p1 = Add(1);
    node *p2 = Add(2);
    node *p3 = Add(3);
    node *p4 = Add(4);
    node *p5 = Add(5);
    node *p6 = Add(6);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    InOrderTraverse(p);
    return 0;
}