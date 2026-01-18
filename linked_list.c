#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};

int main(){
    struct node* head = malloc(sizeof(struct node));
    struct node* ptr = malloc(sizeof(struct node));
    ptr = head;
    // head->data = 0;
    // head->link = NULL;
    for (int i = 0; i < 10; i++)
    {
        struct node* temp = malloc(si   zeof(struct node));
        temp->data = i;
        temp->link = NULL;
        ptr->link = temp;
        ptr = temp;
        printf("%d ",ptr->data);
        
    }
    printf("%d",ptr->data);
    free(ptr);
    free(head);
    return 0;
}