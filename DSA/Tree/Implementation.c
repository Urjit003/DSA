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
int main()
{
    node *p = Add(0);
    node *p1 = Add(1);
    node *p2 = Add(2);
    p->left = p1;
    p->right = p2;
    return 0;
}