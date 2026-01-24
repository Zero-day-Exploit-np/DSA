#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }

    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int value)
{
    if (isFull(s))
    {
        printf("stack is full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\ncan not pop the element in stack.stack is EMPTY\n");
    }
    else
    {
        int value = s->arr[s->top];
        s->top = s->top - 1;
        printf("%d element has been pop\n", value);
    }
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

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 1);
    push(s, 1);

    print(s);
    pop(s);
    pop(s);

    return 0;
}