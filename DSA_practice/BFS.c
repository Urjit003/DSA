#include <stdio.h>
#define MAX 100
int queue[MAX];
int front, rear;
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("\nQueue is full.");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}

int dequeue()
{
    int val = 0;
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty");
        return val;
    }
    else
    {
        val = queue[front];
        front++;
        return val;
    }
}
int isempty()
{
    int val = 0;
    if (front == -1 || front > rear)
    {
        val = 1;
    }
    return val;
}
void display()
{
    int i;
    printf("\n");
    for (i = front; i <= rear; i++)
    {
        printf("\t %d", queue[i]);
    }
}
int main()
{
    int i = 0, node, j;
    int visited[5] = {0, 0, 0, 0, 0};
    int a[][5] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}};
    printf("\n %d", i);
    visited[i] = 1;
    enqueue(i);
    while (!isempty())
    {
        node = dequeue();
        // printf("\n node : %d ",node);
        for (j = 0; j < 5; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("\t%d", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    return 0;
}