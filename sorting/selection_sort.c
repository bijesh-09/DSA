#include<stdio.h>

void selection_sort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            //this loop finds the index of minimum element in unsorted array from j to n-1
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
            
        }
        if (arr[i] == arr[min_idx])
        {
            continue;//continue will skip the current ith iteration
        }
        else{
            //swap arr[i] and arr[min_idx]
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            
        }
    }
    
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}