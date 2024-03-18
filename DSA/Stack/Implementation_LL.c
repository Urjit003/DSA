#include <stdio.h>
#include <stdlib.h>
// Implementing Stack using Linked list 
struct Node
{
    int data;
    struct Node *next;
};
int IsFull(struct Node *ptr);
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int IsFull(struct Node *top)
{
    // if we cant dynamically create space , then the stack if FULL
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        return 1;
    free(n);
    return 0;
}
int IsEmpty(struct Node *top)
{
    if (top == NULL)
        return 1; // true
    return 0;     // false
}
struct Node *push(struct Node *top, int x)
{
    if (!IsFull(top))
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }

    printf("\nStack Overflow");
}
int pop(struct Node *top)
{
    if (!IsEmpty(top))
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }

    printf("\nStack Underflow");
}
int StackBottom(struct Node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    return (top->data);
}
int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if ((ptr == NULL))
    {
        return -1; // failure
    }
    return ptr->data;
}
int StackTop(struct Node *top)
{
    return top->data;
}
int main()
{
    struct Node *top = NULL;

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    traverse(top);
    int pos = 3;
    printf("The Element at position %d is [%d]\n", pos, peek(top, pos));
    printf("The TOP in stack is %d", StackTop(top));
    if (top->next == NULL)
    {
        free(top);
        top = NULL;
    }

    return 0;
}