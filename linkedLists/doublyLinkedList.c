#include <stdio.h>
#include <stdlib.h>

static int numberOfNodes = 0;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void displayList(struct node *head)
{
    // traversing and showing data through linked list
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {

        struct node *temp = head;
        printf("Linked List: ");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        printf("Total no. of nodes in linked list: %d\n", numberOfNodes);
        printf("\n");
    }
}

void insertFront(struct node **loaclhead)
{
    struct node *frontNode = (struct node *)malloc(sizeof(struct node));

    int frontValue;
    printf("Enter data to insert at the front: ");
    scanf("%d", &frontValue);

    printf("Inserting %d at front...\n", frontValue);
    frontNode->data = frontValue;
    frontNode->prev = NULL;
    frontNode->next = *loaclhead;
    if (*loaclhead != NULL)
    {
        (*loaclhead)->prev = frontNode;
    }
    *loaclhead = frontNode;

    numberOfNodes++;
    displayList(*loaclhead);
}

int main()
{
    /*
    A pointer always takes the same amount of memory, regardless of what it points to:

    64-bit system: All pointers = 8 bytes
    32-bit system: All pointers = 4 bytes
    cuz the pointer only stores the address of the variables which is alwas the same size in a given system,
     so the size of pointer is not affected by the data type it points to.
    */
    struct node *head = (struct node *)malloc(sizeof(struct node)); //head needs to point the dynmaically allocated node , cuz if head is null then the process of creating list is imposiible
    struct node *ptr = NULL; // for linking nodes together

    printf("How many no. of data: ");
    scanf("%d", &numberOfNodes);
    if (numberOfNodes == 0 || numberOfNodes < 0)
    {
        printf("Invalid number of nodes. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < numberOfNodes; i++)
    {
        int value;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &value);
        struct node *current = (struct node *)malloc(sizeof(struct node));
        if (i == 0)
        {
            head;
            head->data = value;
            head->prev = NULL;
            head->next = NULL;
            ptr = head;
        }
        else
        {
            current->data = value;
            current->prev = ptr;
            current->next = NULL;
            ptr->next = current;
            ptr = current;
        }
    }

    insertFront(&head);

    return 0;
}