#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
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

    head->data = 1;
    head->next = a;

    a->data = 2;
    a->next = b;

    b->data = 3;
    b->next = c;

    c->data = 4;
    c->next = head;

    display(head);

    return 0;
}