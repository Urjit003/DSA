#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} node;
void PreOrder(node *root, int level);
void PostOrder(node *root, int level);
void InOrder(node *root, int level);
void FreeTree(node *root);
node *Add(int data)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    if (n)
    {
        n->data = data;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void PreOrder(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < level; i++)
    {
        printf(" ");
    }

    printf("|-- (%d)\n", root->data);
    PreOrder(root->left, level + 1);
    PreOrder(root->right, level + 1);
}
void PostOrder(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left, level + 1);
    PostOrder(root->right, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf(" ");
    }
    printf("|-- (%d)\n", root->data);
}
void InOrder(node *root, int level)
{

    InOrder(root->left, level + 1);
    printf("|-- (%d)\n", root->data);
    InOrder(root->right, level + 1);
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
int GetUserChoice()
{
    int choice, validinput = 0;
    while (!validinput)
    {
        if (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        else
        {
            validinput = 1;
        }
    }
    return choice;
}
int GetUserDecision()
{
    int decision, validinput = 0;
    while (!validinput)
    {
        printf("Enter 0 to continue and 1 to end \n");
        if (scanf("%d", &decision) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            printf("Invalid Input \n");
        }
        else if (decision != 0 && decision != 1)
        {
            printf("Invalid Input \n");
        }
        else
        {
            validinput = 1;
        }
    }
    return decision;
}
int main()
{
    node *p = Add(0);  // root
    node *p1 = Add(1); // left
    node *p2 = Add(2); // right
    node *p3 = Add(3);
    node *p4 = Add(4);
    node *p5 = Add(5);
    node *p6 = Add(6);
    node *p7 = Add(7);
    node *p8 = Add(8);
    node *p9 = Add(9);
    node *p10 = Add(10);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    p3->left = p7;
    p3->right = p8;

    p4->left = p9;
    p4->right = p10;
    int choice, ShouldExit = 0;
    while (!ShouldExit)
    {
        printf("Enter 1 for PreOrder | 2 for PostOrder | 3 for InOrder \n");
        int choice = GetUserChoice();

        switch (choice)
        {
        case 1:
            printf("PreOrder traverse \n");
            PreOrder(p, 0);
            printf("\n");
            ShouldExit = GetUserDecision();
            break;
        case 2:
            printf("PostOrder traverse \n");
            PostOrder(p, 0);
            printf("\n");
            ShouldExit = GetUserDecision();
            break;

        case 3:
            printf("InOrder traverse \n");
            InOrder(p, 0);
            printf("\n");
            ShouldExit = GetUserDecision();
            break;

        default:
            printf("Enter a Valid choice \n");
            break;
        }
    }
    FreeTree(p);
    return 0;
}
