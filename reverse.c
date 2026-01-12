// reverse the array 
// #include<stdio.h>
// void reverse(int array[], int size){
//     int temp[size];
//     for(int i=0; i<size; i++){
//         temp[i]=array[size-1-i];
//     }
//     for(int i=0; i<size; i++){
//         printf("temp[%d]=%d\n",i,temp[i]);
//     }
// }
// int main(){
//     int array[5]={1,2,3,4,5};
//     int size=5;
//     reverse(array, size);
//     return 0;
// }

// reverse the array without using extra space
#include<stdio.h>
void reverse(int array[], int size){
    int start=0, end = size-1;
    int temp;

    while(start<end){
        temp=array[start];
        array[start]=array[end];
        array[end]=temp;
        start++;
        end--;
    }
   
    
}
int main(){ 
    int array[5]={1,2,3,4,5};
    int size=5;
    reverse(array, size);
 for (int i = 0; i < size; i++)
    {
        printf("array[%d]=%d\n",i,array[i]);
    }
    return 0;
}