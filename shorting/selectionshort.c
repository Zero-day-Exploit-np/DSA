#include<stdio.h>
int main(){
    int a[]={5,4,3,2,1,0};
    int size=6;
    int key,j;

    for(int i=0; i<size; i++){
        key=a[i];
        j=i;
        while(j<size){
            if(a[j]<key){
                key=a[j];
            }
        }
    }


return 0;
}