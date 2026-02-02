#include <stdio.h>
void insertionshort(int *arr, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void print(int *arr, int size)
{
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {1, 2, 6, 4, 5};
    print(arr, 5);
    insertionshort(arr, 5);
    print(arr, 5);

    return 0;
}