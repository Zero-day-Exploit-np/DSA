#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b)
{
    return a > b ? a : b;
}
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

struct Node *rightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->right), height(y->left)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;
    return x;
}

struct Node *leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    y->height = max(height(y->right), height(y->left)) + 1;
    x->height = max(height(x->right), height(x->left)) + 1;
    return y;
}

struct Node *insert(struct Node *node, int data)
{
    // 1. Normal BST insertion
    if (node == NULL)
        return NodeCreate(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; // No duplicates allowed

    // 2. Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor
    int bf = getBalanceFactor(node);

    // 4. Rotation cases

    // Left Left Case
    if (bf > 1 && data < node->left->data)
        return rightRotation(node);

    // Right Right Case
    if (bf < -1 && data > node->right->data)
        return leftRotation(node);

    // Left Right Case
    if (bf > 1 && data > node->left->data)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    // Right Left Case
    if (bf < -1 && data < node->right->data)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
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
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);
    return 0;
}