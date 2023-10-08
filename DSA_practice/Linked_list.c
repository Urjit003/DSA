#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void traverse(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("[%d]%s", ptr->data, (!ptr->next) ? "" : "->");
        ptr = ptr->next;
    }
    printf("\n");
}
Node *AddToStart(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}
Node *AddToEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    traverse(head);
    head = AddToEnd(head, 10);
    head = AddToEnd(head, 20);
    traverse(head);
    return 0;
}