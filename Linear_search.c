#include<stdio.h>
void searching(int array[],int size,int key){
    for(int i=0; i<size; i++){
        if(array[i]==key){
            printf("key found at the index:%d",i);
        }
    }
}
int main(){
int array[5]={1,2,3,4,5};
int size = 5;
int key;
printf("enter the key to search: ");
scanf("%d",&key);
searching(array,size,key);
return 0;
}