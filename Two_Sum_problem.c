#include<stdio.h>
int main(){
int array[5]={1,2,3,4,5};
int target=9;
for(int i=0; i<5; i++){
    for(int j=i+1;j<5;j++){
        if(array[i]+array[j]==target){
            printf(" %d[%d] and %d[%d] ",array[i],i,array[j],j);

        }
    }
}
return 0;
}