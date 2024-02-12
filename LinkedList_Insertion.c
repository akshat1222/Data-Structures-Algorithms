#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements of linked list are: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *InsertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *InsertAtIndex(struct Node *head, int index, int data)
{
    if (index == 0)
    {
        InsertAtFirst(head,data);
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *p = head;
        int i = 0;
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
}

struct Node *InsertAfterNode(struct Node *prev, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prev->next;
    prev->next = ptr;
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
}

struct Node *Reverse(struct Node *head)
{
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        return prev;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 45;
    head->next = second;

    second->data = 55;
    second->next = third;

    third->data = 65;
    third->next = NULL;

    printf("Linked list before insertion:\n");
    LinkedListTraversal(head);

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
        head = InsertAtIndex(head, ind, b);
        break;
    case 3:
        printf("Enter number you want to insert:\n");
        scanf("%d", &c);
        printf("Linked List after insertion:\n");
        InsertAfterNode(second, c);
        break;
    case 4:
        printf("Enter number you want to insert at the end:\n");
        scanf("%d", &d);
        printf("Linked List after insertion:\n");
        InsertAtEnd(head, d);
    default:
        printf("Please select a valid choice:\n");
        break;
    }
    LinkedListTraversal(head);
}