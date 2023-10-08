#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void traverse(node *ptr)
{
    while (ptr != NULL)
    {
        printf("[%1d]%s", ptr->data, (!ptr->next) ? "" : "->");
        ptr = ptr->next;
    }
    printf("\n");
}
node *AddToEnd(node *head, int data)
{
    node *n = head;
    node *ptr = (node *)malloc(sizeof(node));
    while (n->next != NULL)
    {
        n = n->next;
    }
    ptr->data = data;
    n->next = ptr;
    ptr->next = NULL;
    return head;
}
node *AddAtTheStart(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
node *AddAfter(node *head, node *prev, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    ptr->next = prev->next;
    prev->next = ptr;

    return head;
}
node *AddInBetween(node *head, int pos, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *p = head;
    int i = 0;
    while (i != pos - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main()
{
    node *a1 = (node *)malloc(sizeof(node));


    a1->data = 0;
    a1->next = NULL;
    
    traverse(a1);
    for (int i = 1; i <= 10; i++)
    {
        a1 = AddToEnd(a1,i);
    }
    
    traverse(a1);
    free(a1);
    return 0;
}