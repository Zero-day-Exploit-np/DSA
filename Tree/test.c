#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Left;
    struct Node *Right;
};

struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->Left = NULL;
    ptr->Right = NULL;
    return ptr;
}
int inorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->Left);
        printf(" %d", ptr->data);
        inorder(ptr->Right);
    }
}
void PostOrder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        PostOrder(ptr->Left);
        PostOrder(ptr->Right);
        printf(" %d", ptr->data);
    }
}
void preorder(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf(" %d", ptr->data);
        preorder(ptr->Left);
        preorder(ptr->Right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->Left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->Right);
    }
    else
    {
        return 1;
    }
}

struct Node *search(struct Node *ptr, int key)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    if (ptr->data == key)
    {
        return ptr;
    }
    else if (ptr->data > key)
    {
        return search(ptr->Left, key);
    }
    else
    {
        return search(ptr->Right, key);
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

    a->Left = b;
    a->Right = c;

    b->Left = d;
    b->Right = e;

    c->Left = NULL;
    c->Right = f;
    printf("in order");
    inorder(a);
    printf("\n");

    printf("post order");
    PostOrder(a);
    printf("\n");

    printf("preorder");
    preorder(a);
    printf("\n");

    struct Node *key = search(a, 202);
    if (key != NULL)
    {
        printf("key found %d", key->data);
    }
    else
    {
        printf("key not found");
    }

    printf("\n");
    printf("IS BST:%d", isBST(a));
    return 0;
}