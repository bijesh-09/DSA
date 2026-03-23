#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int numberOfNodes = 0; // global variable to keep track of number of nodes

typedef struct circularDoubly
{
    int data;
    struct circularDoubly *next;
    struct circularDoubly *prev;
} node;

node *createNode(int value)
{
    node *createdNode = (node *)malloc(sizeof(node));
    createdNode->data = value;
    createdNode->next = NULL;
    createdNode->prev = NULL;
    return createdNode;
}

void displayList(node *head)
{
    // traversing and showing data through linked list
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {

        node *temp = head;
        printf("Circular Doubly Linked List:\n");
        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("(Back to head: %d)\n", head->data);
        printf("Total no. of nodes in linked list: %d\n", numberOfNodes);
    }
}

void insertAtFront(node **localhead)
{

    int value;
    printf("\nEnter data to insert at front: ");
    scanf("%d", &value);

    node *newNode = createNode(value);
    if (*localhead == NULL)
    {
        *localhead = newNode;
        newNode->next = *localhead;
        newNode->prev = *localhead;
    }

    node *end = *localhead;
    while (end->next != *localhead)
    {
        end = end->next;
    }
    newNode->next = *localhead;
    newNode->prev = end;
    (*localhead)->prev = newNode;
    end->next = newNode;
    *localhead = newNode; // update head to new node

    numberOfNodes++;
    displayList(*localhead);
}

void insertAtEnd(node **localhead)
{

    int value;
    printf("\nEnter data to insert at end: ");
    scanf("%d", &value);

    node *newNode = createNode(value);
    if (*localhead == NULL)
    {
        *localhead = newNode;
        newNode->next = *localhead;
        newNode->prev = *localhead;
    }

    node *end = *localhead;
    while (end->next != *localhead)
    {
        end = end->next;
    }
    newNode->prev = end;
    newNode->next = *localhead;
    end->next = newNode;
    (*localhead)->prev = newNode;

    numberOfNodes++;
    displayList(*localhead);
}

void insertAtPosition(node **localhead)
{
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

    node *newNode = createNode(value);

    if (*localhead == NULL)
    {
        newNode->next = *localhead;
        newNode->prev = *localhead;
        *localhead = newNode;
        return;
    }
    else
    {
        node *temp = *localhead;
        for (int i = 1; i < position - 1 && temp->next != *localhead; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        numberOfNodes++;
        displayList(*localhead);
    }
}

void deleteFromFront(node **localhead)
{
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

    node *end = *localhead;
    while (end->next != *localhead)
    {
        end = end->next;
    }
    node *nodeToDelete = *localhead;
    *localhead = (*localhead)->next;
    (*localhead)->prev = end;
    end->next = *localhead;
    free(nodeToDelete);
    numberOfNodes--;
    displayList(*localhead);
}

void deleteFromEnd(node **localhead)
{
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

    node *temp = *localhead;
    while (temp->next->next != *localhead)
    {
        temp = temp->next;
    }
    node *nodeToDelete = temp->next;
    temp->next = *localhead;
    (*localhead)->prev = temp;
    free(nodeToDelete);
    numberOfNodes--;
    displayList(*localhead);
}

void deleteFromPosition(node **localhead)
{
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
        deleteFromFront(localhead); // sending the actual address of main head
        return;
    }

    node *temp = *localhead;
    for (int i = 1; i < position - 1 && temp->next != *localhead; i++)
    {
        temp = temp->next;
    }

    if (temp->next == *localhead)
    {
        printf("Position %d does not exist in the list.\n", position);
        return;
    }

    node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;
    free(nodeToDelete);

    numberOfNodes--;
    displayList(*localhead);
}

int main()
{
    node *head;
    node *end;

    printf("How many nodes do you want to create? ");
    scanf("%d", &numberOfNodes);

    for (int i = 0; i < numberOfNodes; i++)
    {
        int value;
        printf("Enter data %d: ", i + 1);
        scanf("%d", &value);

        if (i == 0)
        {
            head = createNode(value);
            end = head;
            end->next = head; // point end to head to make it circular
            end->prev = head; // point prev to head as well for doubly circular
        }
        else
        {
            end->next = createNode(value);
            end->next->prev = end; // link prev pointer
            end = end->next;       // traverse to end which is a newly created node
            end->next = head;
            head->prev = end; // maintain circular from both directions
        }
    }

    insertAtFront(&head);

    insertAtEnd(&head);

    insertAtPosition(&head);

    deleteFromFront(&head);

    deleteFromEnd(&head);

    deleteFromPosition(&head);

    return 0;
}
