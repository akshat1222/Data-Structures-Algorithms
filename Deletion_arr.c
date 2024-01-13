
#include <stdio.h>
#include <stdlib.h>
int deleteelement(int arr[], int size, int index)
{
    for (int i = index; i <= size; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int showVal(int arr[],int size)
{   
     for (int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
}

int main()
{
    int index,size;
    int arr[40];
    printf("enter no of elements in array:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    } 
    printf("enter index of element you want to delete");
    scanf("%d",&index);
    deleteelement(arr,size,index);
    size-=1;
    printf("Following are the index of array:\n");
    showVal(arr, size);
}