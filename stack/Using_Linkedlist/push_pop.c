#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *ptr, int data)
{
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    a->data = data;
    a->next = ptr;
    return a;
}

void print(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty cannot pop element\n");
        return 0;
    }
    struct Node *a = ptr;
    ptr = ptr->next;
    free(a);
    return ptr;
}
int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = NULL;
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = push(head, 6);
    head = push(head, 7);
    head = push(head, 8);

    print(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);

    print(head);

    return 0;
}