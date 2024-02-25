#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraverse(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Elements of linked lists are: %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *q = head->next;
    do
    {
        q = q->next;
    } while (q->next != head);
    q->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *InsertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *InsertAfterNode(struct Node *head, struct Node *prevnode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 55;
    head->next = second;

    second->data = 66;
    second->next = third;

    third->data = 77;
    third->next = head;

    printf("Linked list before insertion:\n");
    LinkedListTraverse(head);

    printf("Select insertion operations you want to perform on linked list:\n");
    printf("1. Select if you want to insert at first node:\n");
    printf("2. Select if you want to insert node at index given:\n");
    printf("3. Select if you want to insert after a node:\n");
    printf("4. Select if you want to insert node at end:\n");
    int x, a, b, c, d, ind;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        printf("Enter number you want to insert:\n");
        scanf("%d", &a);
        printf("Linked List after insertion:\n");
        head = InsertAtFirst(head, a);
        break;
    case 2:
        printf("Enter number you want to insert:\n");
        scanf("%d", &b);
        printf("Enter index:\n");
        scanf("%d", &ind);
        printf("Linked List after insertion:\n");
        head = InsertAtIndex(head,b,ind);
        break;
    case 3:
        printf("Enter number you want to insert:\n");
        scanf("%d", &c);
        printf("Linked List after insertion:\n");
        head = InsertAfterNode(head, second, c);
        break;
    case 4:
        printf("Enter number you want to insert at the end:\n");
        scanf("%d", &d);
        printf("Linked List after insertion:\n");
        head = InsertAtEnd(head,d);
    default:
        printf("Please select a valid choice:\n");
        break;
    }
     LinkedListTraverse(head);
}