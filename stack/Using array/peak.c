#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }

    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }

    return 0;
}

int push(struct stack *ptr, int data)
{
    if (isfull(ptr))
    {
        printf("%d cannot push stack overflow\n", data);
        return 0;
    }

    ptr->top++;
    ptr->arr[ptr->top] = data;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("cannot pop stack is empty.\n");
        return 0;
    }
    int value = ptr->arr[ptr->top];
    ptr->top = ptr->top - 1;
    printf(" %d element is pop\n", value);
}

int peak(struct stack *ptr, int position)
{
    if ((ptr->top - position + 1) < 0)
    {
        printf("cannot peak stack is empty.\n");
        return -1;
    }

    return (ptr->top - position + 1);
}

void print(struct stack *ptr)
{
    printf("Element in stack:");
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf(" %d ", ptr->arr[ptr->top - i]);
    }
    printf("\n");
}

int main()
{
    struct stack *a = (struct stack *)malloc(sizeof(struct stack));
    a->size = 10;
    a->top = -1;
    a->arr = (int *)malloc(a->size * sizeof(int));

    push(a, 1);
    push(a, 2);
    push(a, 3);
    push(a, 4);
    push(a, 5);
    push(a, 6);
    push(a, 7);
    push(a, 8);
    push(a, 9);
    push(a, 10);
    push(a, 11);
    print(a);

    pop(a);
    pop(a);

    print(a);

    return 0;
}