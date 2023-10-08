#include <stdio.h>
#include <stdlib.h>
// implementing stack using array
typedef struct
{
    int top;
    int size;
    int *arr;
} stack;
int IsFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // true
    }
    return 0; // false
}
int IsEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // true
    }
    return 0; // false
}
int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 7;
    s->top++;

    if (IsEmpty(s))
    {
        printf("The Stack is empty");
    }
    else
    {
        printf("\nThe Stack is not empty");
        printf("\n%d", s->arr[s->top]);
    }
    return 0;
}