#include<stdio.h>
void insert(int array[], int index, int element, int size){
for(int i=size; i>=index; i--){
    array[i]=array[i-1];
}
array[index]=element;

for(int i = 0; i<size+1; i++){
    printf("array[%d]=%d\n", i, array[i]);
}
}
int main(){
int array[5] = {1,2,3,4,5};
int size= 5;
int index,element;
printf("enter the index and element: ");
scanf("%d %d",&index, &element);
insert(array,index, element, size);
    return 0;
}