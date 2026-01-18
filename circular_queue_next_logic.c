#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int queue[MAX];
int rear = -1;
int front = 0;
int count = 0;  // Track number of elements

bool isFull()
{
    return count == MAX;  // Check if count reaches MAX
}

bool isEmpty()
{
    return count == 0;  // Check if count is 0
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        count++;
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
        int data = queue[front];
        printf("Dequeued: %d\n", data);
        front = (front + 1) % MAX;
        count--;
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
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // This should show underflow
    return 0;
}
