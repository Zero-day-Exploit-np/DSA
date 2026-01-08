// Delete element at index k.
#include<stdio.h>
void delete(int array[], int size, int index){
for(int i=index; i<size-1; i++){
    array[i]=array[i+1];
}
for(int i=0; i<size-1; i++){
        printf("array[%d]=%d\n", i, array[i]);

}
}

int main(){
int array[5]={1,2,3,4,5};
int size = 5;
int index;
printf("enter the deleted element at index: ");
scanf("%d",&index);
delete(array,size,index);
return 0;
}