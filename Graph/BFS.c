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

    int u;
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int b[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    printf("%d",i);
    visited[i]=1;
    enqueue(a,i);
    while(!isempty(a)){
         node  = dequeue(a);
         for (int  j = 0; j < 7; j++)
         {
            if(b[node][j]==1&&visited[j]==0){
                printf(" %d", j);
                visited[j]=1;
                enqueue(a,j);
            }
         }
         
    }
    return 0;
}
