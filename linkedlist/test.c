#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void display(struct Node * head){
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
}

struct Node * insertAtfirst(struct Node * head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node * p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node * p=head;
    ptr->data=data;
      for(int i=0; i<index-1; i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;

    return head;
}

struct Node * deleteAtFirst(struct Node * head){
    struct Node * p=head;
    head=p->next;
    free(p);
    return head;
}

struct Node * DeleteAtEnd(struct Node * head){
    struct Node * a=head;
    struct Node * b=head->next;
    while(b->next!=NULL){
        a=a->next;
        b=b->next;
    }
    a->next=NULL;
    free(b);
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * a=head;
    struct Node * b = head->next;
    for(int i=0; i<index-1; i++){
        a=a->next;
        b=b->next;
    }
    a->next=b->next;
    free(b);
    return head;
}

int main(){
    struct Node *head;
    struct Node * a;
    struct Node * b;
    struct Node * c;
    head=(struct Node*)malloc(sizeof(struct Node));
    a=(struct Node*)malloc(sizeof(struct Node));
    b=(struct Node*)malloc(sizeof(struct Node));
    c=(struct Node*)malloc(sizeof(struct Node));

    head->data=1;
    head->next=a;

    a->data=2;
    a->next=b;
    
    b->data=3;
    b->next=c;

    c->data=4;
    c->next=NULL;
    
    display(head);
    printf("\n");

    head=insertAtfirst(head,0);
    display(head);
    printf("\n");

    head=insertAtEnd(head,5);
    display(head);
    printf("\n");

     head=insertAtIndex(head,6,2);
    display(head);
    printf("\n");

    head=deleteAtFirst(head);
    display(head);
    printf("\n");

    head=DeleteAtEnd(head);
    display(head);
    printf("\n");


    head=deleteAtIndex(head,1);
    display(head);
    printf("\n");

return 0;
}