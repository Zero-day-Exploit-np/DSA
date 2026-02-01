
#include <stdio.h>
#include <limits.h>
void removeduplicate(int arr[], int size)
{
    int a = 1;
    int second;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[a] = arr[i];
            a++;
        }
    }
    for (int i = 0; i < a; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }
}
int main()
{
    int arr[9] = {1, 1, 1, 3, 4, 4, 55, 55, 99};
    int size = 9;
    removeduplicate(arr, size);

    return 0;
}