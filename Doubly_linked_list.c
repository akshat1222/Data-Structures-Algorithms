#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void LinkedListTraverse(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Elements of DoublyLinkedlList are: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *Reverse(struct Node *head)
{
    struct Node *ptr1 = head, *ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    return ptr1;
}

struct Node *DeleteFirst(struct Node *head)
{
    struct Node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct Node *DeleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
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

struct Node *DeleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    free(q);
    p->next = NULL;
    return head;
}

struct Node *DeleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Value not found:\n");
    }
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
    head->prev = NULL;
    head->next = second;

    second->data = 66;
    second->prev = head;
    second->next = third;

    third->data = 77;
    third->prev = second;
    third->next = fourth;

    fourth->data = 88;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Doubly linked list traversal:\n");
    LinkedListTraverse(head);
    printf("Select deletion operations you want to perform on doubly linked list:\n");
    printf("1. Select if you want to delete the first node:\n");
    printf("2. Select if you want to delete node with index given:\n");
    printf("3. Select if you want to delete last node:\n");
    printf("4. Select if you want to delete node with value given:\n");
    printf("5. Select if you want to reverse doubly linked list:\n");
    int x,a,ind;
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        printf("Doubly Linked List after deletion:\n");
        head = DeleteFirst(head);
        break;
    case 2:
        printf("Enter index you want to delete in:\n");
        scanf("%d",&ind);
        printf("Doubly Linked List after deletion:\n");
        head = DeleteAtIndex(head, ind);
        break;
    case 3:
        printf("Doubly Linked List after deletion:\n");
        head = DeleteAtLast(head);
        break;
    case 4:
        printf("Enter value you want to delete:\n");
        scanf("%d",&a);
        printf("Doubly Linked List after deletion:\n");
        head = DeleteAtValue(head,a);
    case 5:
       printf("Reverse traversal of doubly linked list:\n");
       head = Reverse(head);
    default:
        printf("Please select a valid choice:\n");
        break;
    }
    LinkedListTraverse(head);
}