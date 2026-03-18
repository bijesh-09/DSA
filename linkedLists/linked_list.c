#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
static int numberOfNodes = 0; // global variable to keep track of number of nodes
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
        while (temp != NULL) // note dont use temp->next != NULL here it will skip last node
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        printf("Total no. of nodes in linked list: %d\n", numberOfNodes);
        printf("\n");
    }
}

void insertAtEnd(struct node *head)
{ // insert at end doesnt need to modify head pointer so passing by value is fine
    // inserting a node at the end of linked list
    if (head == NULL)
    {
        printf("List is empty. Cannot insert at the end.\n");
    }
    else
    {
        struct node *endNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data to insert at the end: ");
        int endValue;
        scanf("%d", &endValue);
        endNode->data = endValue;
        endNode->next = NULL;
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = endNode;
        printf("Inserting at end...\n");
        numberOfNodes++;//make sure to increment the node count before calling displayList
        displayList(head);
    }
}
// insertion at front method 1:
//  void insertAtFront(struct node** head){// this head is local pointer, not the original head pointer in main
//      //inserting a node at the front of linked list
//      // **head will hold the address of original head pointer of main in its address, not the address of node pointed by the head of main
//      struct node *frontNode = malloc(sizeof(struct node));
//      printf("Enter data to insert at the front: ");
//      int frontValue;
//      scanf("%d", &frontValue);
//      frontNode->data = frontValue;
//      frontNode->next = *head;//using *head cuz "head" is a local pointer here and it wont affect the main() head. so we directly mainpulate the main() head which is *head
//      *head = frontNode;
//      numberOfNodes++;
//      displayList(*head);
//  }

// NOTE IF WE DONT USE PASS BY REFERENCE OF HEAD THEN THE arbirtrary INSERTION WILL NOT WORK PROPERLY since it will get the outdated head pointer if we insert at front before this function call

// insertion at front method 2:
// we can pass by reference by returning the updated head pointer from the function and assigning it to head in main
struct node *insertAtFront(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot insert at front.\n");
        return head;
    }
    else
    {
        struct node *frontNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data to insert at the front: ");
        int frontValue;
        scanf("%d", &frontValue);
        frontNode->data = frontValue;
        frontNode->next = head;
        head = frontNode;
        printf("Inserting at front...\n");
        numberOfNodes++;
        // displayList(head);//the modified local head is passed to display function, but dont do this cuz it may confuse you into thinking that main() head is also modified here
        return head; // returning updated head pointer
    }
}

void insertAtArbitraryPosition(struct node *head)
{ // insert at arbitrary position doesnt need to modify head pointer so passing by value is fine
    // inserting a node at arbitrary position of linked list
    // to be implemented
    int insertPosition, value;
    printf("Enter value to insert at arbitrary position: ");
    scanf("%d", &value);
    printf("Enter a position to insert the value %d in the node: ", value);
    scanf("%d", &insertPosition);

    // code to insert at arbitrary position
    if (insertPosition == 1)
    {
        printf("Position 1 is reserved for inserting at front. Use insertAtFront function.\n");
    }
    else if (insertPosition >= numberOfNodes)
    {
        printf("Invalid position. Position should be < %d.\n", numberOfNodes);
    }
    else if (insertPosition < 1)
    {
        printf("Invalid position. Position should be >= 1.\n");
    }
    else
    {
        printf("Inserting %d at position %d...\n", value, insertPosition);
        struct node *arbitraryNode = (struct node*)malloc(sizeof(struct node));
        arbitraryNode->data = value;
        arbitraryNode->next = NULL;
        // temp is the traversing pointer
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        for (int i = 0; i < insertPosition - 2; i++) //if insertPosition is 2, then for loop wont run, so temp will at head, and ofc thats what we need to perform insertion at 2nd position of the list
        {
            temp = temp->next;
        }
        arbitraryNode->next = temp->next;
        temp->next = arbitraryNode;
        numberOfNodes++;//make sure to increment the node count before calling displayList
        displayList(head);
    }
}
// deletion at front
struct node *deleteAtFront(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Deleting front node... The list has only one node. Deleting the only node...\n");
        free(head);
        numberOfNodes--;
        return NULL; // But dont do this: head = NULL ; return head;
    }
    else
    {
        printf("Deleting front node...\n");
        struct node *temp = head;
        head = head->next;
        free(temp);
        numberOfNodes--;
        return head;
    }
}

// deletion at end method 1:
//  struct node* deleteAtEnd(struct node* head){
//      //to be implemented
//      struct node* lastNodeTraverser = head;
//      struct node* secondLastNode = head;

//     while (lastNodeTraverser->next != NULL)
//     {
//         secondLastNode = lastNodeTraverser;
//         lastNodeTraverser = lastNodeTraverser->next;
//     }
//     if (lastNodeTraverser == head)
//     {
//         //only one node in the list
//         printf("Deleting the only node in the list...\n");
//         free(head);
//         free(lastNodeTraverser);
//         free(secondLastNode);
//         numberOfNodes--;
//         return NULL;
//     }
//     else{
//         printf("Deleting last node...\n");
//         secondLastNode->next = NULL;
//         free(lastNodeTraverser);
//         return head;
//     }
// }

struct node *deleteAtEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete.\n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Deleting last node... The list has only one node. Deleting the only node...\n");
        free(head);
        numberOfNodes--;
        return NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("Deleting last node...\n");
        free(temp->next);
        temp->next = NULL;
        numberOfNodes--;
        return head;
    }
}

void deleteAtArbitraryPosition(struct node *head)
{
    // to be implemented
    int deletePosition;
    printf("Enter position to delete the node: ");
    scanf("%d", &deletePosition);

    if (deletePosition == 1)
    {
        printf("Position 1 is reserved for deleting at front. Use deleteAtFront function.\n");
    }
    else if (deletePosition >= numberOfNodes)
    {
        printf("Invalid position. Position should be < %d.\n", numberOfNodes);
    }
    else if (deletePosition < 1)
    {
        printf("Invalid position. Position should be >= 1.\n");
    }
    else
    {
        printf("Deleting node at position %d...\n", deletePosition);
        struct node *prev = head;
        struct node *current = head;
        for (int i = 0; i < deletePosition - 1; i++)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
        numberOfNodes--;
        displayList(head);
    }
}

struct node* reverseList(struct node *head)
{
    struct node* nextCarrierNode = NULL;
    struct node* prevHolderNode = NULL;
    while (head != NULL)
    {
        nextCarrierNode = head->next;// nextVarrier points to next node before breaking the link
        head->next = prevHolderNode;//head will assign its next to prevHolderNode to reverse the link
        prevHolderNode = head;// move prevHolderNode one step forward where head is currently pointing
        head = nextCarrierNode;// move head one step forward using nextCarrierNode, since head previoous position is now hold by prevHolderNode
    }
    head = prevHolderNode;//prevHolderNode will be the last node processed which will be the new head after reversal
    printf("Reversing the linked list...\n");
    return head;

}
void searchNode(struct node* head){
    int searchValue , searchedCount = 0 ;
    
    printf("Enter value to search the node in the linked list: ");
    scanf("%d", &searchValue);
    struct node* temp = head;
    printf("The node(s) with %d is being searched:\n",searchValue);
    while (temp->next != NULL)
    {
        if (temp->data == searchValue)
        {
            searchedCount++;
        }
        temp = temp->next;
    }
    if (searchedCount == 0)
    {
        printf("Value %d not found in the linked list.\n", searchValue);
    }
    else
    {
        printf("Value %d found %d time(s) in the linked list.\n", searchValue, searchedCount);
    }

}

void destroyList(struct node* head){
    printf("Destroying the linked list...\n");
    while (head != NULL)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    displayList(head);
}

int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = NULL;

    // adding datas to linked list
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
        struct node *current = (struct node*)malloc(sizeof(struct node));
        if (i == 0)
        {
            head->data = value;
            head->next = NULL;
            ptr = head;
        }
        else
        {
            current->data = value;
            current->next = NULL;
            ptr->next = current;
            ptr = current;
        }
    }
    // displaying user input linked list
    displayList(head);

    // inserting at the end and displaying updated linked list
    insertAtEnd(head); // here head is passed by value

    // inserting at the front and displaying updated linked list
    //  insertAtFront(&head);//here address of head is passed to modify head pointer cuz head is changing when we insert at front

    //for method1 of insertion at front, we have to provide &head , so that the stuct node** holds the actual address of main head, and the main head will be modified in the called fn due to the call by reference method
    // insertAtFront(&head);

    //for method-2 of insertion at front
    head = insertAtFront(head); // updating head pointer with returned updated head pointer
    displayList(head);

    // inserting at arbitrary position and displaying updated linked list
    insertAtArbitraryPosition(head);

    head = deleteAtFront(head);
    displayList(head);

    head = deleteAtEnd(head);
    displayList(head);

    deleteAtArbitraryPosition(head);

    head = reverseList(head);
    displayList(head);

    searchNode(head);

    destroyList(head);

    free(head);
    free(ptr);
    return 0;
}