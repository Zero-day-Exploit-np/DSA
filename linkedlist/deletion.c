#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void display(struct Node *head){
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
}

// delete at first
struct Node* DeletionAtFirst(struct Node* head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

// deleting form last 
struct Node * deleteAtEnd(struct Node * head){
    struct Node * prev=head;
    struct Node * curr=head->next;
    while(curr->next!=NULL){

        prev=prev->next;
        curr=curr->next;
    }
    prev->next=NULL;
    free(curr);
    return head;
}

// deleting from index 
struct Node * deletingAtIndex(struct Node * head, int index){
    struct Node * p=head;
    struct Node * q=head->next;
    for(int i=0; i<index-1; i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
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
head = DeletionAtFirst(head);
display(head);
printf("\n");

head=deleteAtEnd(head);
display(head);
printf("\n");

head=deletingAtIndex(head,1);
display(head);
printf("\n");

return 0;
}