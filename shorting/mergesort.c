#include <stdio.h>
void merge(int *arr, int mid, int low, int high)
{
    int array[high+1];
    int i=low, k;
    k = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            array[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            array[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        array[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        array[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = array[i];
    }
}
void mergesort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}
void print(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {9, 14, 4, 8, 7, 5, 6};
    mergesort(arr, 0, 6);
    print(arr, 7);
    return 0;
}