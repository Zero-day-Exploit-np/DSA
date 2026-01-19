#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node * next;
};
void display(struct Node * head){
    while(head!=NULL){
        printf(" %d ", head->data);
        head=head->next;
    }
}

struct Node * searching(struct Node * head, int data){
    int a=0;
    for(int i=0; head!=NULL; i++){
        if(head->data==data){
            printf("data found %d\n",data);
            a++;
        }
        head=head->next;
    }
    if(a==0){
        printf("data not found\n");

    }
}

int main(){
struct Node * head;
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
searching(head,5);

return 0;
}