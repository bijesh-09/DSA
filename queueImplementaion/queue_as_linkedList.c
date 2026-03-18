#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct myQueue
{
    struct node* front;
    struct node* rear;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct myQueue* createQueue(){
    struct myQueue* q = (struct myQueue*) malloc(sizeof(struct myQueue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct myQueue* q){
    return q->front == NULL;
}

void enqueue(struct myQueue* q, int value){
    struct node* temp = createNode(value);
    printf("Enqueued element: %d\n",value);
    if (isEmpty(q))
    {
        q->front = q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
    
}

void dequeue(struct myQueue* q){
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else{
        struct node* temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        
        int dequeuedValue = temp->data;
        printf("Dequeued element: %d\n",dequeuedValue);
        free(temp);
    }
    
}

void peek(struct myQueue* q){
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Front element: %d\n",q->front->data);
    }
    
}

int main(){
    struct myQueue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20); 
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    peek(q);
    dequeue(q);
    peek(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q); // This should show underflow
    peek(q);

    return 0;
}

