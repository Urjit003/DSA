#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int top, size;
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
int match(char a, char b)
{
    if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
    {
        return 1; // balanced
    }
    return 0; // unbalanced
}
int Multi_Parenthesis_matching(char *exp)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
        {
            if (IsEmpty(sp))
            {
                return 0; // unbalanced
            }
            char popped_ch = pop(sp);
            if (!(match(popped_ch, exp[i])))
            {
                return 0; // unbalanced
            }
        }
    }
    if (IsEmpty(sp))
    {
        return 1;
    } // successful
    free(sp);

    return 0;
}
int main()
{

    char *expression = "a + b -c *a []";
    if (Multi_Parenthesis_matching(expression))
    {
        printf("parenthesis are matching");
    }
    else
    {
        printf("parenthesis are not matching");
    }
    return 0;
}