#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 5

int deque[MAXSIZE];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return (front == 0 && rear == MAXSIZE - 1) || front == rear + 1;
}

void insertFront(int data)
{
    if (isFull())
    {
        printf("Deque is full, cannot insert %d at front\n", data);
    }
    else if (isEmpty())
    {
        front = rear = 0;
        deque[front] = data;
        printf("Inserted %d at front\n", data);
    }
    else if (front == 0)
    {
        front = MAXSIZE - 1;
        deque[front] = data;
        printf("Inserted %d at front\n", data);
    }
    else
    {
        deque[--front] = data;
        printf("Inserted %d at front\n", data);
    }
}

void insertRear(int data)
{
    if (isFull())
    {
        printf("Deque is full, cannot insert %d at rear\n", data);
    }
    else if (isEmpty())
    {
        rear = front = 0;
        deque[rear] = data;
        printf("Inserted %d at rear\n", data);
    }
    else if (rear == MAXSIZE - 1)
    {
        rear = 0;
        deque[rear] = data;
        printf("Inserted %d at rear\n", data);
    }
    else
    {
        deque[++rear] = data;
        printf("Inserted %d at rear\n", data);
    }
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque is empty, cannot delete from front\n");
    }
    else if (front == rear)
    {
        printf("Deleted %d from front\n", deque[front]);
        front = rear = -1;
    }
    else if (front == MAXSIZE - 1)
    {
        printf("Deleted %d from front\n", deque[front]);
        front = 0;
    }
    else
    {
        printf("Deleted %d from front\n", deque[front++]);
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque is empty, cannot delete from rear\n");
    }
    else if (front == rear)
    {
        printf("Deleted %d from rear\n", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Deleted %d from rear\n", deque[rear]);
        rear = MAXSIZE - 1;
    }
    else
    {
        printf("Deleted %d from rear\n", deque[rear--]);
    }
}

void displayDeque()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Deque elements: ");
        printf("[DEBUG: front=%d, rear=%d] ", front, rear);
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", deque[i]);
            }
            printf("\n");
        }
        else
        {
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", deque[i]);
            }
            for (int i = front; i <= MAXSIZE - 1; i++)
            {
                printf("%d ", deque[i]);
            }
            printf("\n");
        }
    }
}

void getFront()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Front element: %d\n", deque[front]);
    }
}
void getRear()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
    }
    else
    {
        printf("Rear element: %d\n", deque[rear]);
    }
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);
    displayDeque();
    getFront();
    getRear();
    deleteFront();
    deleteRear();
    displayDeque();
    return 0;
}