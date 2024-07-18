#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("[%d]%s", ptr->data, (ptr->next == NULL) ? "-> [NULL]":"->");
        ptr = ptr->next;
    }
    printf("\n");
}
Node *InsertAtTheEnd(Node *head, int data) {
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
int main (){ struct Node *head, *second, *third, *beforeHead;

    // allocated in HEAP
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    for (int i = 1; i <= 10; i++)
    {
        if(i == 3) continue;
        head= InsertAtTheEnd(head,i);
    }

    traverse(head);
    free(head);
    return 0;
    }