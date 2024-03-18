#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *InsertAtTheEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
Node *InsertAfterANode(Node *head, Node *PreviousNode, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = PreviousNode->next;
    PreviousNode->next = ptr;
    return head;
}
Node *DeleteAtEnd(Node *head)
{
    // Node *ptr = (Node *) malloc(sizeof(Node));
    Node *p = head;

    while (p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    return head;
}
void LinkedListTraverse(Node *head)
{

    for (int i = 0; head != NULL; i++)
    {
        printf("%d%s element in LL is %d \n", i + 1, (i + 1 == 1) ? "st" : (i + 1 == 2) ? "nd"
                                                                       : (i + 1 == 3)   ? "rd"
                                                                                        : "th",
               head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    Node *head, *second, *third;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    LinkedListTraverse(head);
    InsertAfterANode(head, second, 40);
    LinkedListTraverse(head);

    return 0;
}