#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void PrintArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int Maximum(int A[], int n)
{
    int max;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i = 0;
    int j = 0;
    int max = Maximum(A, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int A[] = {3, 7, 15, 27, 8, 10, 20};
    int n = 7;

    PrintArray(A, n);
    CountSort(A, n);
    PrintArray(A, n);
}