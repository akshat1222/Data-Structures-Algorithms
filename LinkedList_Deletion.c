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
        printf("Elements of Linked List are:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *Deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    if (index == 0)
    {
        Deletefirst(head);
    }
    else
    {

        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        struct Node *q = p->next;
        p->next = q->next;
        free(q);
        return head;
    }
}

struct Node *DeleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *DeleteWithValue(struct Node *head, int value)
{
    if (value == head->data)
    {
        Deletefirst(head);
    }
    else
    {
        struct Node *p = head;
        struct Node *q = head->next;
        while (q->data != value && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data = value)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
            printf("Element not found:\n");
        }
        return head;
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

    head->data = 55;
    head->next = second;

    second->data = 66;
    second->next = third;

    third->data = 77;
    third->next = NULL;

    printf("Linked list before deletion:\n");
    LinkedListTraversal(head);
    printf("Select deletion operations you want to perform on linked list:\n");
    printf("1. Select if you want to delete the first node:\n");
    printf("2. Select if you want to delete node with index given:\n");
    printf("3. Select if you want to delete last node:\n");
    printf("4. Select if you want to delete node with value given:\n");
    int x, a, ind;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        printf("Linked List after deletion:\n");
        head = Deletefirst(head);
        break;
    case 2:
        printf("Enter index you want to delete in:\n");
        scanf("%d", &ind);
        printf("Linked List after deletion:\n");
        head = DeleteAtIndex(head, ind);
        break;
    case 3:
        printf("Linked List after deletion:\n");
        head = DeleteAtLast(head);
        break;
    case 4:
        printf("Enter value you want to delete:\n");
        scanf("%d", &a);
        printf("Linked List after deletion:\n");
        head = DeleteWithValue(head, a);
        break;
    default:
        printf("Please select a valid choice:\n");
        break;
    }
    LinkedListTraversal(head);
}