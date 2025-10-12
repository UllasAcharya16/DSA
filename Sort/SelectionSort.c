#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        
        int si =  i; //smallest Index
        for (int j = i+1; j < n; j++)
        {

            if (arr[j] < arr[si])
            {
                si = j;
            
            }
        }
         swap(&arr[i], &arr[si]);

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
    SelectionSort(arr, n);
    printArray(arr, n);
}