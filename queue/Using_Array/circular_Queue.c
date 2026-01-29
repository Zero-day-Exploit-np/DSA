#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};
int isfull(struct queue *p)
{
    return (((p->r + 1) % p->size) == p->f);
}

int isempty(struct queue *p)
{
    return (p->r == p->f);
}

void enqueue(struct queue *q, int data)
{
    if (isfull(q))
    {
        printf("queue is full.\n");
        // return;
    }
    else
    {

        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
        printf("Enqueue element: %d\n", data);
        // return;
    }
}

int dequeue(struct queue *q)
{
    if (isempty(q))
    {
        printf("queue is empty.\n");
        return -1;
    }

    q->f = (q->f + 1) % q->size;
    printf("element is dequeue = %d\n", q->arr[q->f]);
}

int main()
{
    struct queue *a = (struct queue *)malloc(sizeof(struct queue));
    a->size = 10;
    a->f = 0;
    a->r = 0;
    a->arr = (int *)malloc(a->size * sizeof(int));

    enqueue(a, 1);
    enqueue(a, 2);
    enqueue(a, 3);
    enqueue(a, 4);
    enqueue(a, 5);
    enqueue(a, 6);
    enqueue(a, 7);
    enqueue(a, 8);
    enqueue(a, 9);
    enqueue(a, 10);
    // enqueue(a, 11);
    enqueue(a, 11);

    dequeue(a);
    dequeue(a);
    dequeue(a);
    dequeue(a);
    dequeue(a);

    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));
    // printf("element is dequeue = %d\n", dequeue(a));

    enqueue(a, 11);
    enqueue(a, 11);
    enqueue(a, 11);
    enqueue(a, 11);

    // enqueue(a, 11);
    enqueue(a, 11);
    // enqueue(a, 11);
    enqueue(a, 11);
    enqueue(a, 11);

    return 0;
}