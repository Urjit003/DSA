#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Queue
{
    int size, f, r, *arr;
} Queue;
int IsEmpty(Queue *q)
{
    if (q->r == q->f)
    {
        return 1; // empty
    }
    return 0; // not empty
}
int IsFull(Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1; // Queue is FULL
    }
    return 0;
}
int Dequeue(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("QUEUE UNDERFLOW\n");
        return 0;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}
void Enqueue(Queue *q, int value)
{
    if (IsFull(q))
        printf("QUEUE OVERFLOW can't insert %d\n", value);
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}
// void Traverse(Queue *q)
// {
//     int currentindex = q->f;
//     while (currentindex != q->r)
//     {
//         printf("%d\n",q->arr[currentindex]);
//         currentindex ++;
//     }

//     // for (int i = q->f; i != q->r;i ++) {
//     //     printf("%d\n",q->arr[i]) ;
//     // }
//     printf("Last element is %d\n", q->arr[q->r]);
// }
int main()
{
    Queue q;
    q.size = 2;
    q.f = q.r = -1;

    q.arr = (int *)malloc(q.size * sizeof(int));
    if (IsEmpty(&q))
    {
        printf("Queue is Empty \n");
    }

    // enqueuing a few elements
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    
    printf("Dequeuing %d\n",Dequeue(&q));
    if (IsEmpty(&q))

    {
        printf("Queue is Empty\n");
    }

    free(q.arr);
    return 0;
}