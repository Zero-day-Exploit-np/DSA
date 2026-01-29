#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int back;
    int size;
    int *arr;
};

int isfull(struct queue *q)
{
    return (q->back == q->size - 1);
}

int isempty(struct queue *q)
{
    return (q->front == q->back);
}

void enqueue(struct queue *q, int data)
{
    if (isfull(q))
    {
        printf("Queue is full\n");
        return;
    }
    q->back++;
    q->arr[q->back] = data;
}

int dequeue(struct queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->arr[q->front];
}

void print(struct queue *q)
{
    for (int i = q->front + 1; i <= q->back; i++)
    {
        printf(" %d ", q->arr[i]);
    }
}

int main()
{
    struct queue *a = (struct queue *)malloc(sizeof(struct queue));

    a->size = 10;
    a->front = -1;
    a->back = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));

    enqueue(a, 1);
    enqueue(a, 2);
    enqueue(a, 3);
    enqueue(a, 4);
    enqueue(a, 5);

    print(a);

    printf("\nDequeued: %d\n", dequeue(a));
    printf("Dequeued: %d\n", dequeue(a));
    printf("Dequeued: %d\n", dequeue(a));

    print(a);

    return 0;
}
