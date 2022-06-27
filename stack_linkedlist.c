#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct node *next;
}

int IsEmpty(struct Node *top)
{
  if (top == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int IsFull(struct Node *top)
{
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (n == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

struct Node *push(struct Node *top,int x)
{
  if(IsFull(top))
  {
    printf("Stack Overflowed\n");
  }
  else
  {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
  }
}

int main()
{
  struct Node *top = NULL;
}