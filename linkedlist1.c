#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a linked list with random values
void create_random_list(struct Node **head, int n)
{
    struct Node *newNode, *temp;

    // Seed the random number generator with current time
    srand(time(0));

    if (n <= 0)
    {
        *head = NULL;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        // Generate random number between 1 and 100
        newNode->data = (rand() % 100) + 1;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            temp = *head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    printf("Random Linked List: ");
    while (temp != NULL)
    {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n;
    
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    
    create_random_list(&head, n);
    displayList(head);
    
    // struct Node *temp = head;
    // head = head->next;
    // free(temp);
    // displayList(head);
    // while (temp->next != NULL)
    // {
        //     struct Node *toFree = temp;
        //     temp = temp->next;
        // }
        // struct Node *addedLastNode = (struct Node *)malloc(sizeof(struct Node));
        // addedLastNode->next = NULL;
        // addedLastNode->data = 3;
        // temp->next = addedLastNode;
        
        // displayList(head);
        
        // while (temp->next!=NULL)
    // {
        //     struct Node *afterThirdNode = (struct Node *)malloc(sizeof(struct Node));
        //     afterThirdNode->data = 3;
        //     afterThirdNode->next = temp->next;
        //     temp->next = afterThirdNode;
        // }
        // displayList(head);
        
        
        struct Node *temp = head;
    while (temp->next->next != NULL){
        temp = temp->next ;
        
    }
    free(temp->next);
    temp->next = NULL;
    displayList(head);
        
        

    return 0;
}