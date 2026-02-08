#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *Right;
};
struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->Right = NULL;
    return ptr;
}
void preorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf(" %d", ptr->data);
        preorder(ptr->left);
        preorder(ptr->Right);
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

    a->left=b;
    a->Right = c;

    b->left = d;
    b->Right = e;

    c->left = NULL;
    c->Right = f;

    preorder(a);

        return 0;
}