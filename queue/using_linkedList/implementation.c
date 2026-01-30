#include <stdio.h>
#include <stdlib.h>
struct Node *f = NULL;
struct Node *r = NULL;
struct Node
{
    int data;
    struct Node *next;
};
void display()
{
    struct Node *ptr = f;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertion(int data)
{
    struct Node *ptr = r;
    struct Node *b = (struct Node *)malloc(sizeof(struct Node));

    if (b == NULL)
    {
        printf("Memory full.\n");
    }
    else
    {
        b->data = data;
        b->next = NULL;
        if (f == NULL)
        {
            r = f = b;
        }
        else
        {
            r->next = b;
            r = b;
        }
    }

}

struct Node *delete()
{
    struct Node *ptr = f;
    f = f->next;
    printf("Element deleted %d\n", ptr->data);
    free(ptr);
}
int main()
{

    insertion(2);
    insertion(3);
    insertion(4);
    insertion(5);
    insertion(6);

    display();

    delete();
    insertion(9);

    printf("\n");
    display();

    return 0;
}