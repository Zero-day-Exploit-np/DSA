#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct Node *NodeCreate(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

struct Node *leftRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->right), height(y->left));
    x->height = max(height(x->right), height(x->left));
}

struct Node *RightRotation(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *t2 = ->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->right), height(y->left));
    x->height = max(height(x->right), height(x->left));
}

int main()
{

    return 0;
}