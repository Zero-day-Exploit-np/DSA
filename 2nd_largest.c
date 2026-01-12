#include <stdio.h>
#include <limits.h>

void sec_lar(int arr[], int size) {
    int max = INT_MIN;
    int sec = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            sec = max;
            max = arr[i];
        } else if (arr[i] < max && arr[i] > sec) {
            sec = arr[i];
        }
    }
    printf("%d",sec);
}
int main(){
 int array[12] = {500, 2, 99, 4, 500, 6, 7, 8, 100, 10, 11, 12};
    int size = 12;
    sec_lar(array,size);
return 0;
}