#include<stdio.h>
void majority(int arr[],int size){
    int count=1;
    int a=arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]==a)
            count++;
        else{
            count--;
            if(count==0){
                a=arr[i];
                count=1;
            }
        }
    }
    printf("Majority element is %d",a);
}
int main(){
int arr[5]={1,2,2,2,1};
int size=5;
majority(arr,size);
return 0;
}