#include <stdio.h>
#include <stdlib.h>

void PrintArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void QuickSort(int A[], int low, int high)
{
    int partitionindex;

    if (low < high)
    {
        partitionindex = partition(A, low, high);
        QuickSort(A, low, partitionindex - 1);
        QuickSort(A, partitionindex + 1, high);
    }
}

int main()
{
    int A[] = {3, 7, 12, 20, 9, 11};
    int n = 6;

    PrintArray(A, n);
    QuickSort(A, 0, n - 1);
    PrintArray(A, n);
}