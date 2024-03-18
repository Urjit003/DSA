#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int size, top;
    int *arr;
} stack;
int IsEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // true
    }
    return 0; // false
}
int IsFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1) // 1 == 1
    {
        return 1; // true
    }
    return 0; // false
} // O(1)
void push(stack *ptr, int value)
{
    if (IsFull(ptr))
    {
        printf("\nStack overflow %d cannot be pushed\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("\nStack Underflow");
        /* code */
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int peek(stack *sp, int i)
{
    int ArrayInd = sp->top - i + 1;
    if (ArrayInd < 0)
    {
        printf("Invalid Position");
    }
    return sp->arr[ArrayInd];
}
int StackTop(stack *sp)
{
    return sp->arr[sp->top];
}
int StackBottom(stack *sp)
{
    return sp->arr[0];
}
int main()
{
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    // printf("Enter the size of your stack\n");
    // scanf("%d",&s->size);
    s->top = -1;
    s->size = 500;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 00);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("%d : %d\n", j, peek(s, j));
    }

    printf("\nThe stack[%d] top is %d ",s->size, StackTop(s));
    printf("\nThe stack[%d] bottom is %d ",s->size, StackBottom(s));
    return 0;
}