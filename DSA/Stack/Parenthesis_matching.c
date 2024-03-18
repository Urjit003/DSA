#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int size, top;
    char *arr;
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
void push(stack *ptr, int value)
{
    if (!IsFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    printf("\nStack overflow %d cannot be pushed\n", value);
}

char pop(stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("\nStack Underflow");
        /* code */
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int ParenthesisMatch(char *exp)
{
    stack *sp = (stack *)malloc(sizeof(stack));

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; i < exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (IsEmpty(sp))
            {
                return 0; // underflow
            }
            pop(sp);
        }
    }
    if (IsEmpty(sp))
    {
        return 1; // balanced
    }
    return 0; // unbalanced
}

int main()
{

    char *expression = "(8) * -- * ^^(9)";
    if (ParenthesisMatch(expression))
        printf("\nParenthesis are matching");
    else
        printf("\nParenthesis are not matching");

    return 0;
}