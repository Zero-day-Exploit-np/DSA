
#include<stdio.h>
#include<stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int* arr = (int*)malloc(total * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j])
            arr[k++] = nums1[i++];
        else
            arr[k++] = nums2[j++];
    }

    while (i < nums1Size)
        arr[k++] = nums1[i++];

    while (j < nums2Size)
        arr[k++] = nums2[j++];

    double median;
    if (total % 2 == 0) {
        median = (arr[total/2 - 1] + arr[total/2]) / 2.0;
    } else {
        median = arr[total/2];
    }

    free(arr);
    return median;
}
     

int main(){
    int nums1[]={1,2,5};
    int nums2[]={3,9,5};
    int nums1Size=3;
    int nums2Size=3;
    float a=findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);
    printf("%f",a);
    return 0;
}