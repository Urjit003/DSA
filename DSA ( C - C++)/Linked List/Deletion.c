#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void Traverse(Node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("Element %d : %d\n", i, head->data);
        head = head->next;
        i++;
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
Node *DeleteAfterANode(Node *head, Node *PreviousNode) {
    Node *ptr = head;
    ptr = PreviousNode ->next;
    PreviousNode ->next = ptr->next;
    free(ptr);
    return head;
}
Node *DeleteAtTheEnd(Node *head) {
    Node *ptr= head;
    while(ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next  = NULL;
    return head;

}
void Runner()
{
    Node *head, *second, *third, *fourth ,*fifth;
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
    fifth = (Node *)malloc(sizeof(Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;


    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = NULL;

    Traverse(head);
    head = DeleteInBetween(head,2);
    Traverse(head);

    free(head);
    free(second);
    free(third);
}
int main()
{
    Runner();
    return 0;
}