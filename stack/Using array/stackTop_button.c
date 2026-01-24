#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    int *arr;
};

int isfull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;     
    }
    return 0;
}

int stackTop(struct stack*ptr){
    printf(" %d\n",ptr->arr[ptr->top]);
}
int stackbutton(struct stack * ptr){
    printf(" %d\n",ptr->arr[0]);
}

int push(struct stack * ptr,int data){
    if(isfull(ptr)){
        printf("stack full cannot push element\n");   
        return 0;
    }

    ptr->top++;
    ptr->arr[ptr->top]=data;
}
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack empty cannot pop element\n");   
        return 0;
    }
    ptr->top--;
}

int peak(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("stack empty cannot peak element\n");   
        return 0;
    }

    for(int i=0; i<ptr->top+1; i++){
        printf(" %d ",ptr->arr[i]);
    }
    printf("\n");
}

int main(){
    struct stack *a= (struct stack*)malloc(sizeof(struct stack));
    a->size=10;
    a->top=-1;
    a->arr=(int*)malloc(a->size* sizeof(int));
    push(a, 1);
    push(a, 2);
    push(a, 3);
    push(a, 4);
    push(a, 5);
    push(a, 6);
    push(a, 7);
    push(a, 8);
    push(a, 9);
    push(a, 10);
  
    peak(a);
    pop(a);
    peak(a);
    stackbutton(a);
    stackTop(a);
    

return 0;
}