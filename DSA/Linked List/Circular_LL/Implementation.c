#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
void traverse(struct Node *ptr)
{
    Node *p = ptr;
    // p = p->next;
    do
    {
        printf("[%d]%s", p->data, (p->next == ptr) ? "":"->");
        p = p->next;
    }while (p != ptr);
    printf("\n");
}
int main()
{
    struct Node *head, *second, *third;

    // allocated in HEAP
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first to second
    head->data = 7;
    head->next = second;
    // Link first to second
    second->data = 71;
    second->next = third;
    // Link first to second
    third->data = 17;
    third->next = head;
    traverse(head);
    return 0;
}
