#include<stdio.h>
void searching(int array[], int size, int key){
    int mid;
    int low=0, high=size-1;

    while(low<=high){
        mid=(low+high)/2;
        if(array[mid]==key){
            printf("found at the index:%d",mid);
                        break;
        }else if (key<array[mid])
        {
            high=mid-1;
        }else {
            low=mid+1;
        }
        
        
    }
}
int main(){
int array[12]={1,2,3,4,5,6,7,8,9,10,11,12};
int size = 12;
int key;
printf("enter the key to search: ");
scanf("%d",&key);
searching(array,size,key);
return 0;
}