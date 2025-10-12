#include <stdio.h>

// int BinarySearch(int nums[],int numsSize, int target)
// {

//     int start = 0;
//     int end = numsSize - 1;
//     int mid;
//     while (start <= end)
//     {

//         // mid = (start + end) / 2; But when strt and end are MAX value it will cause u Overlow
//         mid =  start +  ( end - start )/ 2;
//         if (nums[mid] < target)
//         {
//             start = mid + 1;
//         }
//         else if (nums[mid] > target)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;
// }

int BinarySearch(int nums[],int numsSize,int start,int end, int target)
{


    if(start <= end)
    {

        // mid = (start + end) / 2; But when strt and end are MAX value it will cause u Overlow
        int mid =  start +  ( end - start )/ 2;
        if (nums[mid] < target)
        {
           return BinarySearch(nums,numsSize,mid +1,end, target);
        }
        else if (nums[mid] > target)
        {
            return BinarySearch(nums,numsSize,start,mid -1, target);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void main()
{

    int nums[] = {-1, 0, 3, 5, 9, 12};

    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int start = 0;
    int end = numsSize - 1;
    int mid;
    int index = BinarySearch(nums,numsSize,start,end, target);


    printf("%d\n", index);
}