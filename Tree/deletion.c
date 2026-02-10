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

struct Node *inorderPredessor(struct Node *ptr)
{
    ptr= ptr->left;
    while (ptr->right != NULL)
    {
        ptr=ptr->right;
    }
    return ptr;    

}

struct Node *deletion(struct Node *ptr, int data)
{
    struct Node *iPre;
    if (ptr == NULL)
    {
        return NULL;
    }
    if (ptr->left == NULL && ptr->right == NULL)
    {
        free(ptr);
        return NULL;
    }
    if (data < ptr->data)
    {
        ptr->left= deletion(ptr->left, data);
    }
    else if (data > ptr->data)
    {
        ptr->right= deletion(ptr->right, data);
    }
    else
    {
        iPre = inorderPredessor(ptr);
        ptr->data = iPre->data;
        ptr->left = deletion(ptr->left, iPre->data);
    }
    return ptr;
}

void inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf(" %d", ptr->data);
        inorder(ptr->right);
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
    inorder(a);
    deletion(a, 10);
    printf("\nAfter insertion:");
    inorder(a);
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