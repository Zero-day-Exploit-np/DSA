#include<stdio.h>
#include<limits.h>
void KadaneAlgo(int arr[], int size){
    int sum=0;
    int maxsum=INT_MIN;
    for(int i=0; i<size; i++){
        sum+=arr[i];
       if(sum>maxsum){
        maxsum=sum;
       }
       if(sum<0){
        sum=0;
       }
    }
    printf("%d",maxsum);
}
int main(){
int arr[5]={1,2,3,4,5};
int size=5;
KadaneAlgo(arr,size);
return 0;
}