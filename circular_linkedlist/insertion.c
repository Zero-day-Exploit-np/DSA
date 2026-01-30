#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertNodeInFirst(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *a = head;
    struct Node *b = (struct Node *)malloc(sizeof(struct Node));
    ptr = ptr->next;
    while (ptr != head)
    {
        a = a->next;
        ptr = ptr->next;
    }
    b->data = data;
    b->next = head;
    a->next = b;
    return b;
}


struct Node * insertNodeEnd(struct Node * head, int data){
    struct Node * ptr= head;
    struct Node * a = (struct Node*)malloc(sizeof(struct Node));
    a->data=data;
    
    ptr=ptr->next;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=a;
    a->next=head;
    return head;
}


struct Node * insertNodeIndex(struct Node * head, int data, int index){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node * a=head;
    struct Node * b=head->next;
    int count=0;
    ptr->data=data;
    while(b!=head && count<index-1){
        a=a->next;
        b=b->next;
        count++;
    }
    ptr->next=b;
    a->next=ptr;
    return head;
}


struct Node * searching(struct Node * head,int value){
    // struct Node * a=head;
    struct Node * b=head;

    do{
        if(b->data==value){
            printf("data Found %d\n",b->data);
        }
        b=b->next;
    }while(b!=head);
}

int main()
{
    struct Node *head;
    struct Node *a;
    struct Node *b;
    struct Node *c;
    head = (struct Node *)malloc(sizeof(struct Node));
    a = (struct Node *)malloc(sizeof(struct Node));
    b = (struct Node *)malloc(sizeof(struct Node));
    c = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = a;

    a->data = 2;
    a->next = b;

    b->data = 3;
    b->next = c;

    c->data = 4;
    c->next = head;

    display(head);
    printf(" \n");

    head = insertNodeInFirst(head, 0);
    display(head);
    printf(" \n");

    head = insertNodeEnd(head, 5);
    head = insertNodeEnd(head, 7);

    display(head);
    printf(" \n");

    head=insertNodeIndex(head,6,3);
    display(head);
    printf(" \n");
    
    searching(head,0);
    return 0;
}