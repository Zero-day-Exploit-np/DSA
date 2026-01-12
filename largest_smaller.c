// time complexity =O(N)
#include<stdio.h>
void minmax(int array[], int size){
    int min, max;
    min=array[0];
    max=array[0];
    for(int i=0; i<size; i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    printf("max= %d, min= %d",max,min);
}
int main(){
int array[5]={1,2,3,4,5};
int size=5;
minmax(array, size);
return 0;
}