#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL; // global top pointer

int isEmpty(){
    return top == NULL;
}

//isFull function is not possible for linked list implementation of stack as we can always allocate memory dynamically until heap memory is exhausted

void push(int value){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Heap Overflow\n");
    }
    else{
        temp->data = value;
        temp->next = top;
        top = temp;
        printf("Pushed element: %d\n",value);
    }
    
}

void pop(){
    if (isEmpty() )
    {
        printf("Stack Underflow\n");
    }
    else{
        struct node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        free(temp);
        printf("Popped element: %d\n",poppedValue);
    }
    
}

void peek(){
    if (isEmpty())
    {
        printf("Stack Underflow! Cannot peek\n");
    }
    else{
        printf("Peeked element: %d\n",top->data);
    }
    
}

int main(){
    push(10);
    push(20); 
    push(30);
    push(40);
    push(50);
    peek();
    pop();
    peek();
    pop();
    pop();
    pop();
    pop();
    pop(); // This should show underflow

    return 0;
}
