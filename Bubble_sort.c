#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void BubbleSort(int *a, int size)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < size-1; i++)
    {
        printf("working on pass number: %d\n",i+1);
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j ] = a[j+1];
                a[j+1] = temp;
                isSorted =0;
            }
        }
        if(isSorted)
        {
            return;
        }
    }
}

int main()
{
    int A[] = {1, 7, 11, 17, 4, 9};

    int size = 6;
    PrintArray(A, size);
    BubbleSort(A, size);
    PrintArray(A, size);
    return 0;
}