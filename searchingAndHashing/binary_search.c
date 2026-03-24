#include <stdio.h>

int binary_search(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int bisearch_rec(int arr[], int target, int left, int right){
    if (left > right)
    {
        return -1;
    }
    else{
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            return bisearch_rec(arr, target, mid+1, right);
        }
        else
        {
            return bisearch_rec(arr, target, left, mid-1);
        }
        
    }
}

int main()
{

    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int resultIndex = binary_search(arr, size, target);
    printf("\nUsing Iterative Binary Search:\n");
    (resultIndex == -1) ? printf("Element is not present in array")
                   : printf("Element is %d and it is present at index %d", arr[resultIndex], resultIndex);

    printf("\nUsing Recursive Binary Search:\n");
    int rec_resultIdx = bisearch_rec(arr, target, 0, size - 1);
    (rec_resultIdx == -1) ? printf("Element is not present in array")
                          : printf("Element is %d and it is present at index %d", arr[rec_resultIdx], rec_resultIdx);
    return 0;
}
