#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int top;
    int size;
    int *arr;
} Stack;
int IsEmpty(Stack *s1)
{
    if (s1->top == -1)
    {
        return 1;
    }
    return 0;
}
int IsFull(Stack *s1)
{
    if (s1->top == s1->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(Stack *s1, int data)
{
    if (!IsFull(s1))
    {
        s1->top++;
        s1->arr[s1->top] = data;
    }
    else
    {
        printf("Stack overflow \n");
    }
}
int pop (Stack *s1) {
    int val = s1->arr[s1->top];
    if(!IsEmpty(s1)) {
        s1->top -- ;
        return val;
    }else {
        printf("Stack under flow cannot pop %d \n",val);
    }
}
int traverse(Stack *s) {
     for (int i = s->top; i >= 0; i--) {
        if (i == 0) {
            printf("[_%d_]\n", s->arr[i]);
        } else {
            printf("[ %d ]\n", s->arr[i]);
        }
    }
    
}
int main()
{
    Stack *s1 = (Stack *)malloc(sizeof(Stack));
    s1->size = 5;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    if (s1)
    {
        printf("Stack created \n");
      for (int i = 1; i <= 5; i++)
      {
        push(s1,i);
      }
      
    }
    traverse(s1);
    // printf("%d\n",pop(s1));
    return 0;
}