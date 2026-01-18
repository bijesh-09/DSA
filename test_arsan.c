#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

int main()
{
    struct Node *node[101]; // array to hold node addresses
    int i;

    for (i = 0; i <= 100; i++)
    {
        node[i] = (struct Node *)malloc(sizeof(struct Node));
        node[i]->data = i;
        node[i]->link = NULL;

        if (i == 0)
        {
            continue; // skip linking for first node
        }
        else
        {
            node[i - 1]->link = node[i];
        }
    }

    /* Optional: print the list to verify */
    struct Node *temp = node[0];
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");

    return 0;
}
