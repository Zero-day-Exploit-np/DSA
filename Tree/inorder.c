#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// Tree
//     17
//     / \
//   15   20
//  / \    \
// 10  16    43
// preOrder = 17 15 20 10 16 43
// postOder = 10 16 15 43 20 17
// inOrder =  10 15 16 17 20 43

void inOrder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        printf(" %d", ptr->data);
        inOrder(ptr->right);
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
    inOrder(a);
    return 0;
}