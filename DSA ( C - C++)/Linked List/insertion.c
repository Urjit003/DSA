// DABHI URJIT
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
        printf("[%d]%s", ptr->data, (ptr->next == NULL) ? "-> [NULL]":"->");
        ptr = ptr->next;
    }
    printf("\n");
}
Node *InsertAtFirst(Node *head, int data)
{
    // Create memory in heap for PTR
    Node *ptr = (Node *)malloc(sizeof(Node));
    // we point ptr's next to head for connection
    ptr->next = head;
    // adding the argument data to ptr's data . OBV
    ptr->data = data;
    return ptr;
}
Node *InsertInBetween(Node *head, int data, int pos)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    int i = 0;
    // we HOLD our P pointer to  the before (to be set) position
    while (i != pos - 1)
    {
        // traverse p untill our desired position's before node
        p = p->next;
        // for increamentation of the loop
        i++;
    }
    // setting the data
    ptr->data = data;
    // newly created node's next now should point to p's next
    //  now the new node points at the position after  e.g[10 | *]--> [12 | ]
    ptr->next = p->next;
    // we create new connection of p to ptr to make our new linked list
    p->next = ptr;
    return head;
}
Node *InsertAtTheEnd(Node *head, int data) // 😎
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
Node *InsertAfterNode(Node *head, Node *prevNode, int data)
{ // 😌
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;

    // connecting the newly created node to the given node's next , to get the reference of the next node
    ptr->next = prevNode->next;
    // setting the link of Previous Node to the new node to break the chain of its the the old 'NEXT node' . 😌
    prevNode->next = ptr;
    return head;
}
Node *InsertAtaData(Node *head , int data) {
    int target;
    Node *p = head , *ptr =(Node *)malloc(sizeof(Node)) , *placeholder;
    ptr->data = data;
    traverse(head);
    printf("Enter the data of a node to search : \n");
    scanf("%d",&target);
    while (p->data != target)   
    {
        p= p->next;
    }
     // placeholder to hold the position of P 
    placeholder = p ; // ph = 10
    ptr->next = placeholder->next;
    // if there isnt a position for P then there will be a INFINIE loop of ptr pointing to itself.
    placeholder->next = ptr;
    return head;
}
int main()
{
    struct Node *head, *second, *third, *beforeHead;

    // allocated in HEAP
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    for (int i = 1; i <= 50; i++)
    {
        InsertAtTheEnd(head,i);
    }
    head = InsertAtaData(head, 144);
    traverse(head);
    
    free(head);
    return 0;
}
