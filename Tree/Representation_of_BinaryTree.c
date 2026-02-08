#include <stdio.h>
#include <malloc.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
int main()
{
    struct Node *Root;
    struct Node *b=createNode(1);
    struct Node *a=createNode(2);
    Root = (struct Node *)malloc(sizeof(struct Node));
    Root->left = a;
    Root->right = b;



    return 0;
}   