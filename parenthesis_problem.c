#include <stdlib.h>
#include <stdio.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int Isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char exp)
{
    if (Isfull(ptr))
    {
        printf("Stack Overflow!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = exp;
    }
}

char pop(struct stack *ptr)
{
    if (Isempty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char popped = ptr->arr[ptr->top];
        ptr->top--;
        return popped;
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int ParenthesisMatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poppedch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (Isempty(sp))
            {
                return 0;
            }
            poppedch = pop(sp);
            if (!match(poppedch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (Isempty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "(8+1)";

    if (ParenthesisMatch(exp))
    {
        printf("Parenthesis matched");
    }
    else
    {
        printf("Parenthesis not matched");
    }
    return 0;
}