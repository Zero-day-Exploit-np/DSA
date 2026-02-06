#include <stdio.h>

int partition(int *arr, int low, int high)
{

    int pivot = arr[low];
    int i = low;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickshort(int *arr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickshort(arr, low, partitionIndex - 1);
        quickshort(arr, partitionIndex + 1, high);
    }
}

void print(int *a, int size){

    for (int i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {3, 5, 1, 2, 4, 8,1};
    print(arr,7);
    quickshort(arr, 0, 6);
    print(arr, 7);

    return 0;
}