#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int queue[MAX];
int rear = -1;
int front = -1;

bool isFull()
{
    return rear == MAX - 1;
}
bool isEmpty()
{
    return front > rear;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = data;
        printf("Enqueued: %d\n", data);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
    }
    else
    {
        int data = queue[front++];
        printf("Dequeued: %d\n", data);
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // This should show overflow
    peek();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // This should show underflow
    return 0;
}