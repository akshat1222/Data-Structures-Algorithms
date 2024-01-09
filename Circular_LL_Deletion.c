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

int Length(struct Node *head)
{
    struct Node *current = head;
    int count = 0;

    if (head == NULL)
    {
        printf("Cricular linked list is empty:\n");
    }
    do
    {
        current = current->next;
        count++;
    } while (current != head);
    return count;
}

struct Node *Deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    do
    {
        q = q->next;
    } while (q->next != head);
    q->next = head->next;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *DeleteAtIndex(struct Node *head, int index)
{
    int len = Length(head);
    int count = 1;
    struct Node *prev = head, *next = head;

    if (head == NULL)
    {
        printf("Delete Last List is empty\n");
    }
    if (index >= len || index < 0)
    {
        printf("Index is not found:\n");
    }

    if (index == 0)
    {
        printf("Index is zero so deleting the first node:\n");
        Deletefirst(head);
    }
    while (len > 0)
    {
        if (index == count)
        {
            prev->next = next->next;
            free(next);
        }
        prev = prev->next;
        next = prev->next;
        len--;
        count++;
    }
}

struct Node *DeleteAtLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    do
    {
        ptr = ptr->next;
        p = p->next;
    } while (p->next != head);
    ptr->next = head;
    free(p);
    return head;
}

struct Node *DeleteWithValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while (p->data != value && p->next != head)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    free(p);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 55;
    head->next = second;

    second->data = 66;
    second->next = third;

    third->data = 77;
    third->next = fourth;

    fourth->data = 88;
    fourth->next = head;
    printf("Circular Linked list before deletion:\n");
    LinkedListTraverse(head);
    printf("Select deletion operations you want to perform on circular linked list:\n");
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
    default:
        printf("Please select a valid choice:\n");
        break;
    }
    LinkedListTraverse(head);
}