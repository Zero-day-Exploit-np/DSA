#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isfull(struct queue *a)
{
    if (a->r == a->size - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(struct queue *a)
{
    if (a->f == a->r)
    {
        return 1;
    }
    return 0;
}

int EnqueueAtEnd(struct queue *ptr, int data)
{
    if (isfull(ptr))
    {
        printf("queue is full.\n");
        return 0;
    }
    ptr->r++;
  return  ptr->arr[ptr->r] = data;
}

int EnqueueAtFirst(struct queue *ptr, int data)
{
    if (ptr->f <= -1)
    {
        printf("queue is full.\n");
        return 0;
    }

    ptr->f--;
   return ptr->arr[ptr->f] = data;
}

int dequeueAtEnd(struct queue *ptr)
{
    if (isempty(ptr))
    {
        printf("queue is empty.\n");
        return 0;
    }
    int val = ptr->arr[ptr->r];
    ptr->r--;
    return val;
}

int dequeueAtFront(struct queue *ptr)
{
    if (isempty(ptr))
    {
        printf("queue is empty.\n");
        return 0;
    }
    ptr->f++;
    return ptr->arr[ptr->f];
}

void print(struct queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf(" %d ", q->arr[i]);
    }
}
int main()
{
    struct queue *a;
    a = (struct queue *)malloc(sizeof(struct queue));
    a->size = 10;
    a->f = a->r = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));

     EnqueueAtEnd(a, 1);
    EnqueueAtEnd(a, 2);
    EnqueueAtEnd(a, 3);
    EnqueueAtEnd(a, 4);
    EnqueueAtEnd(a, 5);
    EnqueueAtEnd(a, 1);
    EnqueueAtEnd(a, 2);
    EnqueueAtEnd(a, 3);
    EnqueueAtEnd(a, 4);
    EnqueueAtEnd(a, 5);
    // EnqueueAtEnd(a, 5);

    print(a);
    printf(" \n%d element is deque.\n",dequeueAtFront(a));
    print(a);
    EnqueueAtFirst(a,1);
    printf("\n");
    print(a);

    return 0;
}