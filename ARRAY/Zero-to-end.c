#include <stdio.h>
void zerotoend(int arr[], int size)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[index] = arr[i];
            index++;
        }
    }

    while (index < size)
    {
        arr[index] = 0;
        index++;
    }
}
int main()
{
    int arr[6] = {1, 2, 0, 0, 5, 6};
    int size = 6;
    zerotoend(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    return 0;
}