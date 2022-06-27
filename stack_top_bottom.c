#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
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

int isEmpty(struct stack *ptr)
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

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow! cannot push %d in stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i)
{

    int arrindex = sp->top - i + 1;
    if (arrindex < 0)
    {
        printf("not a valid position");
        return -1;
    }
    else
    {
        return sp->arr[arrindex];
    }
}

int stacktop(struct stack *s)
{
    return s->arr[s->top];
}

int stackbottom(struct stack *s)
{
    return s->arr[0];
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));
    push(s, 12);
    push(s, 22);
    push(s, 5);
    push(s, 8);
    push(s, 99);
    push(s, 45);
    push(s, 54);
    push(s, 89);
    push(s, 98);
    push(s, 17);  //--> pushed 10 values
    push(s, 100); //--> stack overflow because stack size is 10
    printf("the top most value of stack is %d\n",stacktop(s));
    printf("the bottom most value of stack is %d\n",stackbottom(s));
    
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }
}