#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int n, target = 12;
    int found_index = -1;

    printf("Enter no. of random integers u want to generate: ");
    scanf("%d",&n);
    
    int* arr =  (int*)malloc(n*sizeof(int) );
    if (arr == NULL)
    {
        return 1;
    }

    srand(time(NULL) );
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; // Random integers between 0 and 99
    }
    

    clock_t start = clock();
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found_index = i;
            break;
        }
        
    }
    
    clock_t end = clock();

    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    if (found_index != -1)
    {
        printf("Target %d found at index %d.\n", target, found_index);
    }
    else
    {
        printf("Target %d not found in the array.\n", target);
    }
    free(arr);
    
    return 0;
}