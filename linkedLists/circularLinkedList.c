#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int numberOfNodes = 0; // global variable to keep track of number of nodes

typedef struct circularLinkedList
{
    int data;
    struct circularLinkedList* next;
} node;

node* createNode(int value){
    node* createdNode = (node*)malloc(sizeof(node));
    createdNode->data = value;
    createdNode->next = NULL;
    return createdNode;

}


void displayList(node* head)
{
    // traversing and showing data through linked list
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {

        node* temp = head;
        printf("Linked List:\n");
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while (temp != head);
        
        printf("(Back to head: %d)\n", head->data);
        printf("Total no. of nodes in linked list: %d\n", numberOfNodes);

        
    }
}

void insertAtFront(node** localhead){

    int value;
    printf("\nEnter data to insert at front: ");
    scanf("%d", &value);
    
    node* newNode = createNode(value);
    if (*localhead == NULL)
    {
        *localhead = newNode;
        newNode->next = *localhead;
    }

    node* end = *localhead;
    while (end->next != *localhead)
    {
        end = end->next;
    }
    newNode->next = *localhead;
    end->next = newNode;
    *localhead = newNode; // update head to new node

    numberOfNodes++;
    displayList(*localhead);
    
}

void insertAtEnd(node** localhead){

    int value;
    printf("\nEnter data to insert at end: ");
    scanf("%d", &value);
    
    node* newNode = createNode(value);
    if (*localhead == NULL)
    {
        *localhead = newNode;
        newNode->next = *localhead;
    }

    node* end = *localhead;
    while (end->next != *localhead)
    {
        end = end->next;
    }
    end->next = newNode;
    end = end->next;
    end->next = *localhead; 

    numberOfNodes++;
    displayList(*localhead);
    
}

void insertAtPosition(node** localhead){
    int position, value;
    printf("\nEnter position to insert at: ");
    scanf("%d", &position);

    if (position == 1)
    {
        insertAtFront(localhead);
        return;
    }

    printf("Enter data to insert: ");
    scanf("%d", &value);

    node* newNode = createNode(value);

    if (*localhead == NULL)
    {
        newNode->next = *localhead;
        *localhead = newNode;
        return;
    }
    else{
        node* temp = *localhead;
        for (int i = 1; i < position-1 && temp->next != *localhead; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        numberOfNodes++;
        displayList(*localhead);
        
    }
    

    
}

void deleteFromFront(node** localhead){
    if (*localhead == NULL)
    {
        printf("List is empty. Cannot delete from front.\n");
        return;
    }

    if ((*localhead)->next == *localhead)
    {
        printf("Only one node in the list. Deleting it will make the list empty.\n");
        free(*localhead);
        *localhead = NULL;
        numberOfNodes--;
        displayList(*localhead);
        return;
    }

    node* end = *localhead;
    while (end->next != *localhead)
    {
        end = end->next;
    }
    *localhead = (*localhead)->next;
    free(end->next);
    end->next = *localhead;
    numberOfNodes--;
    displayList(*localhead);
    
}

void deleteFromEnd(node** localhead){
    if (*localhead == NULL)
    {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    if ((*localhead)->next == *localhead)
    {
        printf("Only one node in the list. Deleting it will make the list empty.\n");
        free(*localhead);
        *localhead = NULL;
        numberOfNodes--;
        displayList(*localhead);
        return;
    }

    node* temp = *localhead;
    while (temp->next->next != *localhead)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = *localhead;
    numberOfNodes--;
    displayList(*localhead);
    
}

void deleteFromPosition(node** localhead){
    int position;
    printf("\nEnter position to delete from: ");
    scanf("%d", &position);

    if (*localhead == NULL)
    {
        printf("List is empty. Cannot delete from position %d.\n", position);
        return;
    }

    if (position == 1)
    {
        deleteFromFront(localhead); //sending the actual address of main head
        return;
    }

    node* temp = *localhead;
    for (int i = 1; i < position-1 && temp->next != *localhead; i++)
    {
        temp = temp->next;
    }

    if (temp->next == *localhead)
    {
        printf("Position %d does not exist in the list.\n", position);
        return;
    }

    node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    
    numberOfNodes--;
    displayList(*localhead);
    
}

int main(){
    node* head;
    node* end;

    printf("How many nodes do you want to create? ");
    scanf("%d", &numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++)
    {
        int value;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &value);

        if (i==0)
        {
            head = createNode(value);
            end = head;
            end->next = head; // point end to head to make it circular
        }
        else{
            end->next = createNode(value);
            end = end->next; //traverse to end which is a newly created node
            end->next = head;
        }
        
    }
    
    insertAtFront(&head);
    
    insertAtEnd(&head);

    insertAtPosition(&head);

    // deleteFromFront(&head);

    // deleteFromEnd(&head);

    deleteFromPosition(&head);

    return 0;
}