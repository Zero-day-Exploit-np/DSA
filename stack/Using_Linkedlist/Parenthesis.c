#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    if (a == NULL)
    {
        return 1;
    }
    free(a);
    return 0;
}

struct Node *pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        // printf("can not pop element stack empty\n");
        printf("unbalance expressions.\n");
        return NULL;
    }
    struct Node *a = ptr;
    ptr = ptr->next;
    // printf("%c element has been pop\n", a->data);
    free(a);
    return ptr;
}

struct Node *push(struct Node *ptr, char data)
{
    if (isFull())
    {
        printf("stack is full cannot push the %c element.\n", data);

        return 0;
    }
    struct Node *a = (struct Node *)malloc(sizeof(struct Node));
    a->data = data;
    a->next = ptr;
    return a;
}


int ismatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int main()
{
    struct Node *head = NULL;

    char s[] = "{[]}";

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            head = push(head, s[i]);
        }
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if (isEmpty(head))
            {
                printf("Unbalance expression.\n");
                return 0;
            }
            char a = head->data;
            head = pop(head);
            if (!ismatching(a, s[i]))
            {
                printf("Unbalance expression.\n");
                return 0;
            }
        }
    }

    if (head == NULL)
    {
        printf("balance expression.\n");
    }
    else
    {
        printf("Unbalance expression.\n");
    }

    // print(head);

    return 0;
}


