#include<stdio.h>
int main(){
    int array[10]={1,2,0,4,0,6,7,8,9,10};
    int posi=0;
    for(int i=0; i<10; i++){
        if(array[i]!=0){
            array[posi]=array[i];
            posi++;
        }
    }

    while (posi<10)
    {
        array[posi++]=0;
    }

    for(int i=0; i<10; i++){
        printf("%d ",array[i]);
    }
    return 0;
}