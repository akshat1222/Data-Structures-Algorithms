#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
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

struct Node *push(struct Node *top, int x)
{
  if (IsFull(top))
  {
    printf("Stack Overflowed\n");
  }
  else
  {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
    return top;
  }
}

int pop(struct Node* tp)
{
  struct Node *p = tp;
  if (IsEmpty(tp))
  {
    printf("Stack Underflow Empty!");
  }
  else
  {
    int element = p->data;
    top = tp->next;
    free(p);
    return element;
  }
}

int main()
{
  top = push(top, 22);
  top = push(top, 33);
  top = push(top, 44);

  int element = pop(top);
  printf("popped element from stack is %d \n", element);

  linkedListTraversal(top);
}