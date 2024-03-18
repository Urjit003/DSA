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
        printf("[%d]%s", ptr->data, (!ptr->next) ? "":"->");
        ptr = ptr->next;
    }
    printf("\n");
}
Node *InsertAtTheEnd(Node *head, int data) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
void ReverseLinkedList(Node *head) {
    Node *prev = NULL;
    Node *p = head;
    while (p!= NULL)
    {
        Node *temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }
    head = prev;
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    for (int i = 0; i < 10; i++)
    {
        head =InsertAtTheEnd(head,rand() % 100);
    }
    traverse(head);
    ReverseLinkedList(head);
    traverse(head);
    return 0;
}