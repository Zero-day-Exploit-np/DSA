// Check if array is sorted
// Problem:
// Return true if array is sorted in non-decreasing order.

#include<stdio.h>
void check(int array[], int size){
    int num=array[0];
    for(int i=0; i<size; i++){
        if(array[i]>=num){
            num=array[i];
        }else{
            printf("array is not sorted ");
            return;
        }
    }
printf("array is sorted");
}
int main(){
int array[5]={1,5,4,3,2};
int size =5;
check(array, size);
return 0;
}