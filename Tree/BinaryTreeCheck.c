#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *Right;
    struct Node *Left;
};
// int check(){
//     for(int i=0)
// }
struct Node *createNode(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->Left = NULL;
    ptr->Right = NULL;
    return ptr;
}

int isBST(struct Node * root)
{
    static struct Node * prev=NULL;
    if(root!=NULL){
        if(!isBST(root->Left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->Right);
    }else{
        return 1;
    }
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
    inorder(a);
    printf("\n");
    printf("%d",isBST(a));

    return 0;
}