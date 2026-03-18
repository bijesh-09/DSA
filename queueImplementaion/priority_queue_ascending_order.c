#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 5

int priorityQueue[MAXSIZE];
int itemCount = 0;

void peek(){
    printf("Peeked element: %d\n", priorityQueue[itemCount-1]);
}

void delete(){
    printf("Deleted element: %d\n", priorityQueue[--itemCount]);
}

bool isEmpty(){
    return itemCount == 0;
}
bool isFull(){
    return itemCount == MAXSIZE;
}

//this function is for descending order priority queue deletion
void deleteForDescendingOrder(){
    printf("Deleted element for Descending Order: %d\n", priorityQueue[0]);
    //shift all elements to left by one position
    for (int  i = 1; i < itemCount; i++)
    {
        priorityQueue[i-1] = priorityQueue[i];
        //note dont do this priorityQueue[i] = priorityQueue[i+1]; cuz if i =4 then i+1 =5 which is out of bounds 
    }
    itemCount--;//dont forget to decrease item count
    
}

void insert(int data){
    if (!isFull())
    {
        if (itemCount == 0)
        {
            priorityQueue[itemCount++] = data;
            printf("Inserted element: %d\n", data);
            printf("Item count: %d\n", itemCount);
        }
        else{
            //shifting lower values than data , to the right end
            int i;
            for (i = itemCount-1; i >= 0; i--)
            {
                if (data > priorityQueue[i])
                {
                    priorityQueue[i+1] = priorityQueue[i];

                }
                else{
                    break;
                }
                
            }
            priorityQueue[i+1] = data;
            itemCount++;
            printf("Inserted element: %d\n", data);
            printf("Item count: %d\n", itemCount);  
        }
        
    }
    
}
void priorityQueueDisplay(){
    if (!isEmpty())
    {
        printf("Priority Queue elements in ascending order of priority: ");
        for (int i = itemCount-1; i>=0 ; i--)
        {
            printf("%d ", priorityQueue[i]);
        }
        printf("\nPriority Queue elements actual arrangement: ");
        for (int i = 0; i < itemCount; i++)
        {
            printf("%d ", priorityQueue[i]);
        }
        
        printf("\n");
        printf("\n");
    }
    else{
        printf("Priority Queue is empty! Cant show how elements are actually arranged inside queue\n");
    }
    
    
}

int main(){
    insert(30);
    insert(50);
    insert(10);
    insert(40);
    insert(20);

    priorityQueueDisplay();
    
    
    return 0;
}
