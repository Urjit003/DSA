#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("[%d]%s", ptr->data, (!ptr->next) ? "":"->");
        ptr = ptr->next;
    }
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
    third->next = NULL;
    traverse(head);
    return 0;
}
