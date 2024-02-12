#include <stdio.h>
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

void push(struct stack *ptr,int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow! cannot push %d in stack\n",val);
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

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));
    push(s,12);
    push(s,22);
    push(s,5);
    push(s,8);
    push(s,99);
    push(s,45);
    push(s,54);
    push(s,89);
    push(s,98);
    push(s,17);//--> pushed 10 values
    push(s,100);//--> stack overflow because stack size is 10
    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));

    printf("popped %d form stack:\n", pop(s));//--> Last in first Out!
    printf("popped %d form stack:\n", pop(s));//--> Last in first Out!
    printf("popped %d form stack:\n", pop(s));//--> Last in first Out!
    printf("popped %d form stack:\n", pop(s));//--> Last in first Out!
}