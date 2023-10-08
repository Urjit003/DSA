#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct CircularQueue
{
    int f, r, size, *arr;
} CircularQueue;
int IsEmpty(CircularQueue *q)
{
    if (q->f == q->r)
    {
        return 1; // yes it is empty
    }
    return 0; // not empty
}
int IsFull(CircularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1; // yes it is FULL
    }
    return 0; // No it is not FULL
}
int Enqueue(CircularQueue *q, int val)
{
    if (IsFull(q))
    {
        printf("Circular Queue OVERFLOWN cannot insert %d\n",val);
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        // IMPORTANT
        // arr[10] =10  <Y>
        // 14 = arr[10]  <!N>
    }
    return val;
}
int Dequeue(CircularQueue *q)
{
    int a = -1;
    if (IsEmpty(q))
    {
        printf("Circular Queue UNDERFLOW\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size; // circular increment
        a = q->arr[q->f];
    }
    return a;
}
void Traverse(CircularQueue *q)
{
    int i = q->f;
    while (i != q->r)
    {
        i = (i + 1) % q->size;
        printf("Element at %d is %d \n",i,q->arr[i]);
    }
    printf("\n");
}
int main()
{
    int length;
    printf("Enter the length of your queue\n");
    scanf("%d",&length);
    CircularQueue q;
    q.f = q.r = -1;
    q.size = length;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("THE SIZE OF YOUR CIRCULAR QUEUE IS %d\n",q.size);
  
    for (int i =1 ; i<=q.size; i++){
        printf("Enter Element for %d :\n",i);
        int ele;
        scanf("%d",&ele);
        Enqueue(&q,ele);
        // Dequeue(&q);
    }
    if(IsFull(&q)) {
        printf("Circular Queue is full\n");
    }
    Traverse(&q);
    for(int i =1 ;i <=q.size ; i ++) {
        printf("%d dequeued at %d\n",Dequeue(&q),i);
    }
    Traverse(&q);
    if(IsEmpty(&q)) {
        printf("Circular Queue is empty\n");
    }
    free(q.arr);
    return 0;
}