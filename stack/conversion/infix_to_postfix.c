#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *head)
{
    if (head->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *head)
{
    if (head->top == head->size - 1)
    {
        return 1;
    }
    return 0;
}

struct stack *push(struct stack *head, char data)
{
    if (isFull(head))
    {
        printf("Stack is full cannot push.\n");
        return 0;
    }
    head->top++;
    head->arr[head->top] = data;
}

struct stack *pop(struct stack *head)
{
    if (isEmpty(head))
    {
        printf("Stack is empty cannot pop.\n");
        return 0;
    }
    head->top--;
}
void print(struct stack *ptr)
{
    printf("Element in stack:");
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf(" %c ", ptr->arr[ptr->top - i]);
    }
    printf("\n");
}
int main()
{
    struct stack *a = (struct stack *)malloc(sizeof(struct stack));
    a->size = 10;
    a->top = -1;
    a->arr = (char *)malloc(a->size * sizeof(char));

    char str[] = "1+2*5/7";

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '+' || str[i] == '*' || str[i] == '/')
        {
            push(a, str[i]);
        }else{
            printf(" %c ",str[i]);
        }
    }
    print(a);
    return 0;
}