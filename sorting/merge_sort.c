#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i = left;    // Starting index of left subarray
    int j = mid + 1; // Starting index of right subarray
    int k = 0;       // Index for temporary array

    // Create temporary array to store merged elements
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    // Merge the two subarrays into temp
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to original array
    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }

    free(temp);
}

// Recursive function to divide array and call merge
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first half
        mergeSort(arr, left, mid);

        // Sort second half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver function
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
