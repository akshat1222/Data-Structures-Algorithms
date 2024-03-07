#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int IsFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int IsEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void EnqueueR(struct queue *q, int val)
{
    if (IsFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("%d Enqueued from rear\n", val);
    }
}

void EnqueueF(struct queue *q, int val)
{
    if (IsFull(q) || q->f == -1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->f--;
        q->arr[q->f] = val;
        printf("%d Enqueued from front\n", val);
    }
}

int DequeueF(struct queue *q)
{
    int val = -1;
    if (IsEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int DequeueR(struct queue *q)
{
    int val = -1;
    if (IsEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        val = q->arr[q->r];
        q->r--;
    }
    return val;
}

void display(struct queue *q)
{
    printf("Element of queue are:\n");
    int i = 0;
    while (i <= (q->r))
    {
        printf("%d\n", q->arr[i]);
        i++;
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->f = q->r = -1;
    q->size = 10;
    q->arr = (int *)malloc(q->size * sizeof(int));

    EnqueueR(q, 48);
    EnqueueR(q, 89);
    EnqueueR(q, 12);
    EnqueueR(q, 64);
    EnqueueR(q, 19);
    EnqueueR(q, 37);
    display(q);
    printf("Element is DeQueued at the front:%d\n", DequeueF(q));
    display(q);
    printf("Element is DeQueued at the rear:%d\n", DequeueR(q));
    display(q);

    return 0;
}