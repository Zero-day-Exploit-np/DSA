#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void print(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
}





int main()
{
    struct Node *head;
    struct Node *a;
    struct Node *b;
    struct Node *c;
    head = (struct Node *)malloc(sizeof(struct Node));
    a = (struct Node *)malloc(sizeof(struct Node));
    b = (struct Node *)malloc(sizeof(struct Node));
    c = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 1;
    head->next = a;

    a->prev = head;
    a->data = 2;
    a->next = b;

    b->prev = a;
    b->data = 3;
    b->next = c;

    c->prev = b;
    c->data = 4;
    c->next = NULL;

    print(head);
    printf("\n");



    return 0;
}