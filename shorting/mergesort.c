#include <stdio.h>

void merge(int *arr, int mid, int low, int high) {
    int size = high - low + 1;
    int array[size];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            array[k++] = arr[i++];
        } else {
            array[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        array[k++] = arr[i++];
    }
    while (j <= high) {
        array[k++] = arr[j++];
    }
    for (int p = 0; p < size; p++) {
        arr[low + p] = array[p];
    }
}

void mergesort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}

void print(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 14, 4, 8, 7, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n - 1);
    print(arr, n);
    return 0;
}
