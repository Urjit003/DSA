#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *f, *r = NULL;
void traverse(Node *n)
{
    int i = 1;
    while (n != NULL)
    {
        printf("Element [%d] : %d \n", i, n->data);
        i++;
        n = n->next;
    }
    printf("\n");
}
int IsFull(Node *ptr)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
    {
        printf("Queue is full\n");
        return 1; // FULL
    }
    return 0; // queue is not full
}
void Enqueue(int val)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!IsFull(n))
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
    else
    {
        printf("Queue full\n");
    }
}
int IsEmpty()
{
    if (f == NULL)
    {
        printf("Queue Underflow\n");
        return 1;
    }
    return 0;
}
int Dequeue()
{
    Node *ptr = f;
    int val = -1; 
    if (f == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
    return 0; //
}
int main()
{

    traverse(f);
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    traverse(f);
    Dequeue();
    traverse(f);

    return 0;
}