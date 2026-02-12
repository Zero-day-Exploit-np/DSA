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

struct Node *rightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->right), height(y->left))+1;
    x->height = max(height(x->right), height(x->left))+1;
    return x;

}

struct Node *leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    y->height = max(height(y->right), height(y->left))+1;
    x->height = max(height(x->right), height(x->left))+1;
    return y;

}

struct Node * insert(struct Node * node, int data){
    if(node==NULL){
        return (NodeCreate(data));
    }
    if(data<node->data){
        node->left= insert(node->left,data);
    }else if (data >node->data)
    {
        node->right=insert(node->right,data);
        return node;
        node->height=1+max(height(node->left),height(node->right));
        int bf =height(node);

        if(bf>1&& data<node->left->data){
            rightRotation(node);
        }

        if (bf <- 1 && data >node->right->data)
        {
            leftRotation(node);
        }

        if (bf > 1 && data < node->left->data)
        {
            rightRotation(node);
        }
    }
    
}

int main()
{

    return 0;
}