#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int queue[MAX];
int rear = -1;
int front = -1;

bool isFull()
{
    return (rear + 1) % MAX == front;
}
bool isEmpty()
{
    return front == -1 ;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1){

            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = data;
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
        if (front == rear)
        {
            front = -1;
            rear = -1;
            printf("Queue is now empty from last dequeue\n");
        }
        else
        {
            front = (front + 1) % MAX;
        }
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