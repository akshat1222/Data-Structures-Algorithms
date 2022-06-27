#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int numOfTesttubes;
    int n = 0, largest1 = 0, largest2 = 0, temp = 0;
    int sum = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    largest1 = arr[0];
    largest2 = arr[1];

    if (largest1 < largest2)
    {
        temp = largest1;
        largest1 = largest2;
        largest2 = temp;
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > largest1)
        {
            largest2 = largest1;
            largest1 = arr[i];
        }
        else if (arr[i] > largest2 && arr[i] != largest1)
        {
            largest2 = arr[i];
        }
    }
    sum = largest1 + largest2;
    printf("Sum of two largest temprature of two test tubes are:%d",sum);
}