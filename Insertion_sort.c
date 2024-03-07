#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void InsertionSort(int *a, int n)
{
    int j ,key;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]> key)
        {
           a[j+1] = a[j];
           j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    int A[] = {1, 7, 11, 17, 4, 9};

    int n = 6;
    PrintArray(A, n);
    InsertionSort(A, n);
    PrintArray(A, n);
}
