#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void SelectionSort(int *a, int n)
{
    int indexofmin, temp;
    for (int i = 0; i <= n - 1; i++)
    {
        indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
    }
}

int main()
{
    int A[] = {1, 7, 12, 14, 9, 4};
    int n = 6;

    PrintArray(A, n);
    SelectionSort(A, n);
    PrintArray(A, n);
}