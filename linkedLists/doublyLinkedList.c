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
            printf("%d <-> ", temp->data);
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

void insertAfter(struct node** localhead){
    
    int position;
    printf("Enter the position where u want to insert data: ");
    scanf("%d", &position);
    
    struct node* temp = *localhead;

    if (*localhead == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (position==1)
    {
        insertFront(localhead);
        return;
    }
    
    for (int i = 0; i <= position-3; i++)
    {
        temp = temp->next; //by the end of the loop temp arrives at the prevnode of designated position
        //this logic helps cuz if the position is null then also we will be able to insert after the last node   
    }

    struct node* prevNode = temp;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    int newNodeValue;
    printf("Enter data to insert: ");
    scanf("%d", &newNodeValue);

    //logic for inserting newNode after prevNode

    newNode->data = newNodeValue;
    //setting up next of prev node and newNode
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    //setting up prev of newNode and next node
    newNode->prev = prevNode;
    if (newNode->next != NULL) // if newnode next is null, then newNode->next->prev is invalid
    {
        newNode->next->prev = newNode;
    }
    numberOfNodes++;
    displayList(*localhead);   
}

void insertEnd(struct node** localhead){
    
    if (localhead == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    
    int endValue;
    printf("Enter data to insert at the end:");
    scanf("%d", &endValue);

    struct node* endNode = (struct node*)malloc(sizeof(struct node));

    struct node* temp = *localhead;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    endNode->data = endValue;
    endNode->next = NULL;
    endNode->prev = temp;
    temp->next = endNode;
    
    numberOfNodes++;
    displayList(*localhead);
}

void deleteFront(struct node** localhead){

    if (*localhead == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *localhead;

    /*
    Note: dont do this: if ( (temp->prev && temp->next) == NULL )
    cuz
    temp->prev && temp->next is a logical AND that returns 0 or 1 (not a pointer)
    So this compares an integer to NULL, which triggers the warning
    More importantly, the logic is inverted — for the front node, temp->prev is always NULL, so (NULL && temp->next) equals 0, making the condition TRUE even when the list has more than 1 node!
    */
    if ( temp->prev == NULL && temp->next == NULL )
    {
        *localhead = NULL;
        free(temp);
        numberOfNodes--;
        printf("Deleting the only node in the list.\n");
        displayList(*localhead);
        return;
    }

    printf("Deleting front node with value %d...\n", temp->data);
    *localhead = temp->next;
    (*localhead)->prev = NULL;
    free(temp);
    numberOfNodes--;
    displayList(*localhead);
}
void deleteEnd(struct node** localhead){

    if (*localhead == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *localhead;

    if ( temp->prev == NULL && temp->next == NULL )
    {
        *localhead = NULL;
        free(temp);
        numberOfNodes--;
        printf("Deleting the only node in the list.\n");
        displayList(*localhead);
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    printf("Deleting end node with value %d...\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
    numberOfNodes--;
    displayList(*localhead);
}

void deleteSpecificNode(struct node** localhead){
    if (*localhead == NULL )
    {
        printf("List is empty.\n");
        return;
    }

    int specificNodeValue;
    printf("Enter the value of the node to delete: ");  
    scanf("%d", &specificNodeValue);

    struct node* temp = *localhead;

    while (temp->next != NULL)
    {
        if (temp->data == specificNodeValue)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp == *localhead)
    {
        deleteFront(localhead); //deletefront and deleteend fns expects double pointer, sso we need to pass the actual addr of main head which is localhead, simply localhead = &mainhead , *localhead = &1stnode
        return;
    }
    else if(temp->next == NULL){
        deleteEnd(localhead);
        return;
    }
    else{
        printf("Deleting the specified node with data value: %d...\n",temp->data);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    numberOfNodes--;
    displayList(*localhead);
    
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

    insertAfter(&head);

    insertEnd(&head);

    deleteFront(&head);

    deleteEnd(&head);

    deleteSpecificNode(&head);
    
    return 0;
}