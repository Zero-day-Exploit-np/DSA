#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void insertion(struct Node *ptr, int data)
{
    struct Node *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        if (data == ptr->data)
        {
            return;
        }
        else if (data < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    struct Node *node = createNode(data);
    if (data < prev->data)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }
}


void preorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf(" %d", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int main()
{
    struct Node *a = createNode(17);
    struct Node *b = createNode(15);
    struct Node *c = createNode(20);
    struct Node *d = createNode(10);
    struct Node *e = createNode(16);
    struct Node *f = createNode(43);

    // Tree
    //     17
    //     / \
    //   15   20
    //  / \    \
    // 10  16    43
    // preOrder = 17 15 20 10 16 43
    // postOder = 10 16 15 43 20 17

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = NULL;
    c->right = f;

    printf("Before insertion:");
    preorder(a);
    insertion(a, 50);
    printf("\nAfter insertion:");
    preorder(a);
    // Tree
    //     17
    //     / \
    //   15   20
    //  / \    \
    // 10  16    43
    // /
    // 5
    return 0;
}