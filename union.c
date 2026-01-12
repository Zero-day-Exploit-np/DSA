//  Union of two sorted arrays
// Problem:
// Print union without duplicates.
#include<stdio.h>

int main(){
int a[5]={1,2,3,4,5};
int asize=5;
int b[7]={4,5,6,7,8,9,10};
int bsize=7;
int i=0; 
int j=0;
while(i<asize&&j<bsize){
    if(a[i]<b[j]){
        printf(" %d",a[i]);
        i++;
    }else if(b[j]<a[i]){
        printf(" %d",b[j]);
        j++;
    }else{
        printf(" %d",a[i]);
        i++;
        j++;
    }
}
while(i<asize){
    printf(" %d",a[i++]);
    
}
while(j<bsize){
        printf(" %d",b[j++]);
        
}
return 0;
}