#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct myArray
{
    int total_s;
    int used_s;
    int *ptr;
};

int createArray(struct myArray *a, int t_size, int u_size)
{
    a->total_s = t_size;
    a->used_s = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));
}

int setVal(struct myArray *a, int size)
{
    int n;
    printf("enter %d elements:\n", size);
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

int showVal(struct myArray *a, int size)
{
    printf("Elements of array are:\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d \n", a->ptr[i]);
    }
}
int indInsert(struct myArray *a, int size, int index, int element)
{
    for (int i = size - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }
    a->ptr[index] = element;
}

int deleteelement(struct myArray *a, int size, int index)
{
    for (int i = index; i <= size; i++)
    {
        a[i] = a[i + 1];
    }
}

int main()
{
    int t_size, u_size;
    int element, index, ele, n, r, ind;
    struct myArray arr;
    printf("Enter total size of array:\n");
    scanf("%d", &t_size);
    printf("Enter number of elements you want to enter:\n");
    scanf("%d", &u_size);
    createArray(&arr, t_size, u_size);
    setVal(&arr, u_size);
    showVal(&arr, u_size);
    printf("Choose an operation to perform on array:\n");
    printf("1. Enter a element in array:\n");
    printf("2. Delete a element from array:\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("Enter element you want to insert:\n");
        scanf("%d", &element);
        printf("Enter index on which you want to put the element:\n");
        scanf("%d", &index);
        indInsert(&arr, u_size, index, element);
        break;
    case 2:
        printf("Enter index of element you want to delete:\n");
        scanf("%d", &ind);
        deleteelement(&arr,u_size,ind);
    default:
        break;
    }
    showVal(&arr, u_size);
}