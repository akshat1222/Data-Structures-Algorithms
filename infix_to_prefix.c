#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int Isfull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Isempty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (Isfull(ptr))
    {
        printf("Stack Overflow!\n");
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

char pop(struct stack *ptr)
{
    if (Isempty(ptr))
    {
        printf("Stack Undeflow\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int ifoperand(char x)
{
    if (x == '*' || x == '/' || x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char x)
{
    if (x == '*' || x == '/')
    {
        return 3;
    }
    if (x == '+' || x == '-')
    {
        return 2;
    }
    return 0;
}

char *InfixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int j = 0;
    int i = 0;
    while (infix[i]!='\0')
    {
        if (!ifoperand(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!Isempty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix of expression is %s", InfixToPostfix(infix));
}