#include<stdio.h>
void selection(int *arr, int size){
    int maxindex;
    for(int i=0; i<size; i++){
        maxindex=i;
        for(int j=i+1; j<size; j++){
            if(arr[maxindex]>arr[j]){
                maxindex=j;
            }
        }
        if(maxindex!=i){
            int temp = arr[i];
           arr[i]= arr[maxindex];
           arr[maxindex]=temp;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}
int main(){
    int arr[]={3,5,1,2,4,8};
    selection(arr,6);

return 0;
}