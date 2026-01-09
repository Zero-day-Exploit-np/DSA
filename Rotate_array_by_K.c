#include<stdio.h>
void reverse(int array[], int start, int end){

    while(start<end){
        int temp=array[start];
        array[start]=array[end];
        array[end]=temp;
        start++;
        end--;
    }
   
    
}
void rotate(int array[], int size, int k){
     k =k%size;
    reverse(array, 0, k-1);
    reverse(array,k,size-1);
    reverse(array,0,size-1);
    
}
int main(){
int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;

    rotate(arr, n, k);

    // Print rotated array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

return 0;
}