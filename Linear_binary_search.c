#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return -1;
}

int binarySearchasc(int arr[], int element, int size)
{
    int low = 0;
    int mid;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return element;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchdesc(int arr[], int element, int size)
{
    int low = 0;
    int mid;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return element;
        }
        else if (arr[mid] > element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int checksort(int arr[], int size)
{
    int i = 0, a = 1, d = 1;
    while ((a == 1 || d == 1) && i < size - 1)
    {
        if (arr[i] < arr[i + 1])
        {
            d = 0;
        }
        else if (arr[i] > arr[i + 1])
        {
            a = 0;
        }
        i++;
    }
    if (a == 1)
        return 1;
    else if (d == 1)
        return 2;
    else
        return 0;
}

int main()
{
    int arr[100];
    int i, size, element, check;
    printf("Enter number of elements you want to enter:\n");
    scanf("%d", &size);
    printf("Enter %d elements of array:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element you want to find:\n");
    scanf("%d", &element);
    check = checksort(arr, size);
    if (check == 1)
    {
        printf("Array is sorted in ascending order:\n");
        printf("So using binary search algorithm:\n");
        int searchIndex = binarySearchasc(arr, element, size);
        if (searchIndex == element)
        {
            printf("Element %d is found in array:\n");
        }
        else if (searchIndex == -1)
        {
            printf("Element not found in the array:\n");
        }
    }
    else if (check == 2)
    {
        printf("Array is sorted in descending order:\n");
        printf("So using binary search algorithm:\n");
        int searchIndex = binarySearchdesc(arr, element, size);
        if (searchIndex == element)
        {
            printf("Element %d is found in array:\n");
        }
        else if (searchIndex == -1)
        {
            printf("Element not found in array:\n");
        }
    }
    else
    {
        printf("Array is not sorted:\n");
        printf("So using linear search algorithm:\n");
        int search = linearSearch(arr, element, size);
        if (search == 1)
        {
            printf("Element %d is found in array:\n", element);
        }
        else if (search == -1)
        {
            printf("Element not found in array:\n");
        }
    }
}