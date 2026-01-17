#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *head){
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
}

struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * p =(struct Node*)malloc(sizeof(struct Node));
    p->data=data;

    p->next=head;
    return p;
}


struct Node *insertAtEnd(struct Node *head,int data){
    struct Node  * p= (struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    struct Node * ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=p;
    p->next=NULL;
    return head;
}

int main(){
struct Node *head;
struct Node *first;
struct Node *second;
head = (struct Node*)malloc(sizeof(struct Node));
first = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
head->data=1;
head->next=first;

first->data=2;
first->next=second;

second->data=3;
second->next=NULL;

display(head);
printf("\n");

head=insertAtFirst(head,4);
display(head);
printf("\n");

head = insertAtEnd(head,5);
display(head);
printf("\n");


return 0;
}