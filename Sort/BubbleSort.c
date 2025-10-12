#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isswap = false;
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isswap = true;
            }
        }
        if(!isswap){
            return;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{

    int arr[] = {2, 4, 5, 1, 3};
    int n = 5;
    BubbleSort(arr, n);
    printArray(arr, n);
}