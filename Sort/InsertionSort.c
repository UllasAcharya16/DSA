#include <stdio.h>


void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i-1;
       
       while(prev>=0 && arr[prev] > curr)
        {

         arr[prev +1] = arr[prev];
         prev -- ;
        }

        arr[prev + 1] = curr; 
      
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
    InsertionSort(arr, n);
    printArray(arr, n);
}