#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("[%d]%s", ptr->data, (ptr->next == NULL) ? "-> [NULL]" : "->");
        ptr = ptr->next;
    }
    printf("\n");
}
Node *DeleteAtBeginnig(Node *head)
{
    if (head == NULL)
    {
        printf("The LL is empty\n");
    }
    Node *p = head;

    p = head->next;

    free(head);
    return p;
}
Node *DeleteInBetween(Node *head, int pos)
{
    Node *ptr = head;
    int i = 0;
    while (i != pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    Node *DeletedNode = ptr->next;
    ptr->next = DeletedNode->next;
    free(DeletedNode);
    return head;
}
Node *DeleteAfterANode(Node *head, Node *PreviousNode)
{
    Node *ptr = head;
    ptr = PreviousNode->next;
    PreviousNode->next = ptr->next;
    free(ptr);
    return head;
}
Node *DeleteAtTheEnd(Node *head)
{
    Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}
Node *InsertAtTheEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    // just to traverse untill the p node's next reaches NULL (which means end of the linked list)
    while (p->next != NULL)
    {
        p = p->next;
    }
    // to set the new data to the newly created node
    ptr->data = data;
    // Because to NOT point P to NULL , we point it to the newly created NODE
    p->next = ptr;
    // Points to NULL so that the linked list ends
    ptr->next = NULL;
    return head;
}
Node *DeleteBeforeData(Node *head)
{
    Node *p, *placeholder;
    int target;
    p = placeholder = head;
    printf("Enter the data of node you wish to delete . \n");
    scanf("%d", &target);
    while (p->data != target)
    {
        placeholder = p ;
        p=p->next;
    }
    placeholder->next = p ->next ;
    free(p);
    traverse(head);
    return head;
}
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    for (int i = 2; i <= 25; i++)
    {
        head = InsertAtTheEnd(head, i);
    }
    traverse(head);
    head = DeleteBeforeData(head);
    return 0;
}