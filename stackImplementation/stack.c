#include<stdio.h>

#define MAXSIZE  5
float stack[MAXSIZE];
int top = -1;

int isFull(){
    return top == MAXSIZE - 1;
}
int isEmpty(){
    return top == -1;
}
void push(float value){
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else{
        stack[++top] = value;
        printf("Pushed element: %.2f\n",value);
    }
    
}
void pop(){
    if(isEmpty())
    {
        printf("Stack Underflow\n");

    }
    else{
        float value = stack[top--];
        printf("Popped element: %.2f\n",value);
    }
}
void peek(){
    if(isEmpty())
    {
        printf("Stack Underflow! Cannot peek\n");

    }
    else{
        float value = stack[top];
        printf("Peeked element: %.2f\n",value);
    }
}
int main(){
    push(10.5);
    push(20.3); 
    push(30.7);
    push(40.2);
    push(50.1);
    push(60.4); // This should show overflow
    peek();
    pop();
    peek();
    pop();
    pop();
    pop();
    pop();
    pop(); // This should show underflow
    peek();
    return 0;
}